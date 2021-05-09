FROM debian:buster
ENV autoindex=on
RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get install -y nginx mariadb-server php7.3 php7.3-fpm php7.3-mysql wget php-mbstring php-xml openssl
RUN chown www-data:www-data /usr/share/nginx/html/ -R
COPY srcs/default.conf /etc/nginx/conf.d/
RUN rm /etc/nginx/sites-enabled/default
COPY srcs/info.php /var/www/html/
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0/phpMyAdmin-5.1.0-english.tar.xz
RUN mkdir /var/www/html/phpmyadmin && tar -xvf /phpMyAdmin-5.1.0-english.tar.xz -C /var/www/html/phpmyadmin --strip-components=1
COPY srcs/config.inc.php /var/www/html/phpmyadmin
RUN wget https://wordpress.org/wordpress-5.7.1.tar.gz
RUN mkdir /var/www/html/wordpress && tar -xvf /wordpress-5.7.1.tar.gz -C /var/www/html/wordpress --strip-components=1
COPY srcs/wp-config.php /var/www/html/wordpress
RUN service mysql start &&\
	echo "CREATE USER 'admin'@'localhost' IDENTIFIED BY 'admin'" | mysql -u root --skip-password &&\
	mysql -u root --skip-password < /var/www/html/phpmyadmin/sql/create_tables.sql &&\
	echo "GRANT SELECT, INSERT, DELETE, UPDATE ON phpmyadmin.* TO 'admin'@'localhost' IDENTIFIED BY 'admin'" | mysql -u root --skip-password &&\
	echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password &&\
	echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'admin'@'localhost' WITH GRANT OPTION;"| mysql -u root --skip-password &&\
	echo "FLUSH PRIVILEGES;"| mysql -u root --skip-password
RUN openssl req -x509 -nodes -days 365 -subj "/C=IT/ST=Italy/L=Rome/O=flwang/OU=42roma/CN=localhost" -newkey rsa:2048 -keyout /etc/ssl/private/tls.key -out /etc/ssl/certs/tls.crt
RUN chown -R www-data:www-data /var/www/*
RUN chmod -R 755 /var/www/*
COPY srcs/autoindex.sh .
RUN chmod 777 autoindex.sh
CMD service mysql start && service php7.3-fpm start && service nginx start && bash 
