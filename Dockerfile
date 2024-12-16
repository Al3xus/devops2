FROM alpine AS build
RUN apk add --no-cache build-base make automake autoconf git pkgconfig glib-dev gtest-dev gtest cmake
WORKDIR /home/optima
RUN git clone --branch branchHTTPserv https://github.com/Al3xus/devops2.git
WORKDIR /home/optima/devops2
RUN autoconf
RUN cmake
FROM alpine
COPY --from=build /home/optima/devops2/myprogram /usr/local/bin/myprogram
ENTRYPOINT ["/usr/local/bin/myprogram"]

