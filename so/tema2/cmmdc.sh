  #!/bin/bash
 
  cmmdc () {
 
a=$1
 
b=$2
 
echo "> $a $b"
 
 
if [ $b -eq 0 ]; then
 
return $a
 
fi
 
 
c=$[ $a % $b ]
 
cmmdc $b $c
 
return $?
  }
 
  echo "parametrii sunt: $@, primul: $1, al doilea: $2"
 
  if [ $1 -lt $2 ]; then
 
echo "ordine incorecta"
 
exit 1
  fi
 
  cmmdc1 $1 $2
  echo "c.m.m.d.c. este: $?"