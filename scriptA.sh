#!/bin/bash
# Функція для запуску нового контейнера
deploy_container() {
    if sudo docker ps -a --format "{{.Names}}" | grep -q "^$1$"; then
        echo "Контейнер $1 вже існує."
        sudo docker rm -f "$1"
    fi
    echo "Створення контейнера $1 на ядрі CPU #$2"
    sudo docker run --name "$1" --cpuset-cpus="$2" --network bridge -d al3xus22/programlab5
}

# Функція для зупинки контейнера
terminate_container() {
    echo "Kill контейнера $1"
    sudo docker kill "$1" && sudo docker rm "$1"
}

# Функція для отримання відсотка використання CPU контейнером
get_cpu_usage() {
    sudo docker stats --no-stream --format "{{.Name}} {{.CPUPerc}}" | grep "$1" | awk '{print $2}' | sed 's/%//'
}

# Функція для визначення номера ядра CPU для контейнера
assign_cpu_core() {
    case $1 in
        primary_container) echo "0" ;;
        backup_container) echo "1" ;;
        tertiary_container) echo "2" ;;
        *) echo "0" ;;
    esac
}

# Функція для перевірки та оновлення образів
check_and_update_images() {
    echo "Перевірка наявності нових версій образів..."
    pull_result=$(sudo docker pull al3xus22/programlab5 | grep "Downloaded newer image")
    if [ -n "$pull_result" ]; then
        echo "Новий образ знайдено. Виконую оновлення контейнерів..."
        for container in primary_container backup_container tertiary_container; do
            if sudo docker ps --format "{{.Names}}" | grep -q "^$container$"; then
                echo "Оновлення контейнера $container..."
                new_instance="${container}_update"
                deploy_container "$new_instance" "$(assign_cpu_core "$container")"
                terminate_container "$container"
                sudo docker rename "$new_instance" "$container"
                echo "$container успішно оновлено."
            fi
        done
    else
        echo "Нових образів не знайдено."
    fi
}

# Функція для постійного моніторингу та керування контейнерами
monitor_and_manage() {
    while true; do
        # Запуск основного контейнера, якщо він неактивний
        if sudo docker ps --format "{{.Names}}" | grep -q "primary_container"; then
            cpu_primary=$(get_cpu_usage "primary_container")
            if (( $(echo "$cpu_primary > 30.0" | bc -l) )); then
                echo "primary_container перевантажений. Активую backup_container..."
                if ! sudo docker ps --format "{{.Names}}" | grep -q "backup_container"; then
                    deploy_container "backup_container" 1
                fi
            fi
        else
            deploy_container "primary_container" 0
        fi

        # Запуск резервного контейнера за потреби
        if sudo docker ps --format "{{.Names}}" | grep -q "backup_container"; then
            cpu_backup=$(get_cpu_usage "backup_container")
            if (( $(echo "$cpu_backup > 30.0" | bc -l) )); then
                echo "backup_container перевантажений. Запуск tertiary_container..."
                if ! sudo docker ps --format "{{.Names}}" | grep -q "tertiary_container"; then
                    deploy_container "tertiary_container" 2
                fi
            fi
        fi

        # Завершення роботи неактивних контейнерів
        for container in tertiary_container backup_container; do
            if sudo docker ps --format "{{.Names}}" | grep -q "$container"; then
                cpu=$(get_cpu_usage "$container")
                if (( $(echo "$cpu < 1.0" | bc -l) )); then
                    echo "$container неактивний. Виконую завершення роботи..."
                    terminate_container "$container"
                fi
            fi
        done

        # Оновлення образів за потреби
        check_and_update_images
        sleep 120
    done
}
# Запуск основного процесу
monitor_and_manage