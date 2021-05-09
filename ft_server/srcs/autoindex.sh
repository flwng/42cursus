if [[ "$1" == off ]]; then
	sed -i 's/autoindex on/autoindex off/g' etc/nginx/conf.d/default.conf
	service nginx reload

elif [[ "$1" == on ]]; then
	sed -i 's/autoindex off/autoindex on/g' etc/nginx/conf.d/default.conf
	service nginx reload
fi
