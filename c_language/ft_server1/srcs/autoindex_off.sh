#!/bin/bash

my_domain="/etc/nginx/sites-available/my_domain"
on="autoindex on"
off="autoindex off"

if [ "$1" == "on" ]
then
        sed -i "s/$off/$on/g" "$my_domain"
else
        sed -i "s/$on/$off/g" "$my_domain"
fi

service nginx restart
