service mysql start
service nginx start

mkdir /var/www/my_domain
chown -R $USER:$USER /var/www/my_domain

# SSL
mkdir /etc/nginx/ssl
openssl req -x509 -sha256 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/my_domain.key -out /etc/nginx/ssl/my_domain.pem -subj "/C=RU/ST=Moscow/L=Moscow/O=21-School/OU=nofloren/CN=my_domain"

# Config Nginx
cp /tmp/nginx-config /etc/nginx/sites-available/my_domain
ln -s /etc/nginx/sites-available/my_domain /etc/nginx/sites-enabled/my_domain
rm -Rf /etc/nginx/sites-enabled/default /etc/nginx/sites-available/default

# Config PHP
mkdir /var/www/my_domain/phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/4.9.5/phpMyAdmin-4.9.5-english.tar.gz
tar -xvf phpMyAdmin-4.9.5-english.tar.gz --strip-components=1 -C /var/www/my_domain/phpmyadmin
chown -R www-data:www-data /var/www/my_domain/phpmyadmin 
cp /var/www/my_domain/phpmyadmin/config{.sample,}.inc.php
chmod -R 755 /var/www/my_domain/phpmyadmin/config.inc.php

# Config MySQL
echo "CREATE DATABASE wordpress;" | mysql
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'admin'@'localhost' IDENTIFIED BY 'admin';" | mysql
echo "UPDATE mysql.user SET plugin='mysql_native_password' WHERE user='admin';" | mysql
echo "FLUSH PRIVILEGES;" | mysql

# Config WordPress
wget -c https://wordpress.org/latest.tar.gz
tar -xvzf latest.tar.gz
mv wordpress/ /var/www/my_domain/
chown -R www-data:www-data /var/www/my_domain/wordpress 
chmod -R 755 /var/www/my_domain/wordpress
cp /tmp/wp-config.php /var/www/my_domain/wordpress/wp-config.php

service nginx restart
service php7.3-fpm start
bash
