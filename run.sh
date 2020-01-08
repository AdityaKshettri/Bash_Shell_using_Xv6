make clean
make 
if [ "$?" = "0" ]
then
make qemu
fi
