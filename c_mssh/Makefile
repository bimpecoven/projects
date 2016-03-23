CC=gcc

mssh:	cscd340hw8.c ./tokenize/makeArgs.o ./utils/myUtils.o ./utils/fileUtil.o ./process/process.o ./pipes/pipes.o ./linkedlist/linkedList.o ./history/history.o ./commands/commands.o ./commands/alias.o
	gcc -g cscd340hw8.c ./tokenize/makeArgs.o ./utils/myUtils.o ./utils/fileUtil.o ./process/process.o ./pipes/pipes.o ./linkedlist/linkedList.o ./history/history.o ./commands/commands.o ./commands/alias.o -o mssh

makeArgs.o:	./tokenize/makeArgs.c ./tokenize/makeArgs.h
	gcc -g -c ./tokenize/makeArgs.c

myUtils.o:	./utils/myUtils.o ./utils/myUtils.h
	gcc -g -c ./utils/myUtils.c

fileUtil.o:	./utils/fileUtil.o ./utils/fileUtil.h
	gcc -g -c ./utils/fileUtil.c

process.o:	./process/process.c ./process/process.h
	gcc -g -c ./process/process.c	

pipes.o:	./pipes/pipes.c ./pipes/pipes.h
	gcc -g -c ./pipes/pipes.c

linkedList.o:	./linkedlist/linkedList.h ./linkedlist/linkedList.c
	gcc -g -c ./linkedlist/linkedList.c

history.o:	./history/history.h ./history/history.c
	gcc -g -c ./history/history.c

commands.o:	./commands/commands.h ./commands/commands.c
	gcc -g -c ./commands/commands.c

alias.o:	./commands/alias.h ./commands/alias.c
	gcc -g -c ./commands/alias.c

clean:
	rm ./pipes/pipes.o	
	rm ./utils/myUtils.o
	rm ./process/process.o
	rm ./tokenize/makeArgs.o
	rm mssh

