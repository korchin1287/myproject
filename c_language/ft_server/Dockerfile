FROM debian:buster

RUN	apt-get update
RUN apt-get -y install vim && apt-get -y install nginx && apt-get -y install wget && apt-get -y install mariadb-server && apt-get -y install openssl

RUN	apt-get -y install php7.3-fpm php7.3-mysql php7.3-mbstring php7.3-zip php7.3-gd php7.3-xml php7.3-gettext php7.3-cgi php7.3-curl php7.3-soap php7.3-xmlrpc

COPY ./srcs/start.sh ./
COPY ./srcs/nginx-config ./tmp/nginx-config
COPY ./srcs/wp-config.php ./tmp/wp-config.php
COPY ./srcs/autoindex_off.sh ./autoindex_off.sh

CMD bash start.sh
