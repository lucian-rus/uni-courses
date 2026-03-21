# ruleaza tot cu -i ca sa inlocuim content-ul fisierului
sed -i 's/continut/content/' ex4.output
sed -i 's/linia/line/' ex4.output
sed -i 's/:/ -/' ex4.output

cat ex4.output