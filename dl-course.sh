
dir="Системы Реального Времени/"
[ -d "$dir" ] && rm -rf "$dir"
#[ -d "$dir" ] || mkdir "$dir"

# http://iamdrunk.ru/teach/Учеба_ПГАТИ/2011-2012/1 семестр/Системы Реального Времени/
url="http://iamdrunk.ru/teach/%D0%A3%D1%87%D0%B5%D0%B1%D0%B0_%D0%9F%D0%93%D0%90%D0%A2%D0%98/2011-2012/1%20%D1%81%D0%B5%D0%BC%D0%B5%D1%81%D1%82%D1%80/%D0%A1%D0%B8%D1%81%D1%82%D0%B5%D0%BC%D1%8B%20%D0%A0%D0%B5%D0%B0%D0%BB%D1%8C%D0%BD%D0%BE%D0%B3%D0%BE%20%D0%92%D1%80%D0%B5%D0%BC%D0%B5%D0%BD%D0%B8/"

wget "$url" \
     --recursive \
     --no-host-directories \
     --cut-dirs=4 \
     --no-parent \
     --reject="index.html*,*.zip,*.7z" \
     -e robots=off \
     --quiet
