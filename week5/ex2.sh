if test ! -f numbers
then
	echo 0 > numbers
fi

if ln numbers numbers.lock
	then
	for i in  `seq 1 50`;
	do
		n=`tail -1 numbers`
		expr $n + 1 >>numbers
	done
	rm numbers.lock
fi

#no race condition manifest as file is being locked for other processes while one is runned
#if in shell we run this script in background AND in foreground, nothing bad occurs
#but if we try more times, for example
# sh ex2.sh
#sh ex2.sh &
#sh ex2.sh
#sh ex2.sh &
#sh ex2.sh
#sh ex2.sh &
#sh ex2.sh
#some processe will be blocked, because they try to use the same file which is locked
#nevertheless, there would be a critical region in the place where we are trying to print number to the file and scan the last number, some repetitons would occur, because foreground process is scanning the same number as the foreground, and that is why its output is not different neitner
