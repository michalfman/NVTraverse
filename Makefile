CFLAGS = -std=c++11 -fpermissive -O3

LFLAGS = -pthread -lssmem

IFLAGS = -I./gc -I.
all: list hash skiplist bstAravind bstEllen

list: mainList.cpp List/ListOriginal.h List/ListIz.h  List/ListTraverse.h Utilities.h
	make -C ./gc/ all
	g++ mainList.cpp $(CFLAGS) $(IFLAGS) -L ./gc/ $(LFLAGS) -o list

hash: mainHash.cpp Hash/HashOriginal.h Hash/HashIz.h  Hash/HashTraverse.h Utilities.h
	make -C ./gc/ all
	g++ mainHash.cpp $(CFLAGS) $(IFLAGS) -L ./gc/ $(LFLAGS) -o hash


skiplist: mainSkiplist.cpp Skiplist/SkiplistOriginal.h Skiplist/SkiplistIz.h  Skiplist/SkiplistTraverse.h Utilities.h
	make -C ./gc/ all
	g++ mainSkiplist.cpp $(CFLAGS) $(IFLAGS) -L ./gc/ $(LFLAGS) -o skiplist

bstAravind: mainBSTAravind.cpp BST/Aravind/BSTAravindIz.h BST/Aravind/BSTAravindTraverse.h BST/Aravind/BSTAravindOriginal.h
	make -C ./gc/ all
	g++ mainBSTAravind.cpp $(CFLAGS) $(IFLAGS) -L ./gc/ $(LFLAGS) -o bstAravind

bstEllen: mainBSTEllen.cpp  BST/Ellen/BSTEllenOriginal.h BST/Ellen/BSTEllenOriginalImpl.h BST/Ellen/BSTEllenIz.h BST/Ellen/BSTEllenIzImpl.h BST/Ellen/BSTEllenTraverse.h BST/Ellen/BSTEllenTraverseImpl.h BST/Ellen/adapter.h
	make -C ./gc/ all
	g++ mainBSTEllen.cpp $(CFLAGS) $(IFLAGS) -L ./gc/ $(LFLAGS) -o bstEllen

clean:
	rm -f list
	rm -f hash
	rm -f skiplist
	rm -f bstAravind
	rm -f bstEllen
	rm -f ./gc/libssmem.a

