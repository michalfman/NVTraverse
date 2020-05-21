/*
 * Utilities.h
 *
 *  Created on: Jul 14, 2016
 *      Author: michal
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <stddef.h> 			//for null
#include <climits>				//for max int
#include <fstream>

#define MAX_THREADS 144
#define FACTOR 100000
#define PADDING 512             // Padding must be multiple of 4 for proper alignment
#define QUEUE_SIZE 1000000
#define CAS __sync_bool_compare_and_swap
#define MFENCE __sync_synchronize

//std::ofstream file;

static void FLUSH(void *p)
{
    asm volatile ("clflush (%0)" :: "r"(p));
}

static void FLUSH(volatile void *p)
{   
    asm volatile ("clflush (%0)" :: "r"(p));
}


static void SFENCE()
{
    asm volatile ("sfence" ::: "memory");
}

/*
void BARRIER(void* p){
	MFENCE();
	FLUSH(p);
	MFENCE();
}

void BARRIER(volatile void* p){
	MFENCE();
	FLUSH(p);
	MFENCE();
}



void OPT_BARRIER(void* p){
	MFENCE();
	FLUSH(p);
}

void OPT_BARRIER(volatile void* p){
	MFENCE();
	FLUSH(p);
}*/
/*
#define BARRIER(p) {FLUSH(p);MFENCE();}
#define OPT_BARRIER(p) {FLUSH(p);}

#ifdef MANUAL_FLUSH
	#define MANUAL(x) x
#else
	#define MANUAL(x) {}
#endif

#ifdef READ_WRITE_FLUSH
	#define RFLUSH(x) x
	#define WFLUSH(x) x
#else
	#ifdef WRITE_FLUSH
		#define RFLUSH(x) {}
		#define WFLUSH(x) x
	#else
		#define RFLUSH(x) {}
		#define WFLUSH(x) {}
	#endif
#endif
*/
//Uncomment below for shared model. Comment definitions above.

static void BARRIER(void* p){
	FLUSH(p);
	MFENCE();
}

static void BARRIER(volatile void* p){
	FLUSH(p);
	MFENCE();
}



static void OPT_BARRIER(void* p){
	FLUSH(p);
	//SFENCE();
}

static void OPT_BARRIER(volatile void* p){
	FLUSH(p);
	//SFENCE();
}

static bool BARRIERM(void* p){
	long pLong = (long)p;
	if((pLong & 2) && !(pLong & 1)){
		return false;
	} else {
		FLUSH(p);
		SFENCE();
		return true;
	}
}

static bool BARRIERM(volatile void* p){
	long pLong = (long)p;
	if((pLong & 2) && !(pLong & 1)){
		return false;
	} else {
		FLUSH(p);
		SFENCE();
		return true;
	}
}



static bool OPT_BARRIERM(void* p){
	long pLong = (long)p;
	if((pLong  & 2) && !(pLong & 1)){
		return false;
	} else {
		FLUSH(p);
		SFENCE();
		return true;
	}
}

static bool OPT_BARRIERM(volatile void* p){
	long pLong = (long)p;
	if((pLong & 2) && !(pLong & 1)){
		return false;
	} else {
		FLUSH(p);
		SFENCE();
		return true;
	}
}
static bool FLUSHM(void* p){
        long pLong = (long)p;
        if((pLong & 2) && !(pLong & 1)){
                return false;
        } else {
                FLUSH(p);
                return true;
        }
}

static bool FLUSHM(volatile void* p){
        long pLong = (long)p;
        if((pLong & 2) && !(pLong & 1)){
                return false;
        } else {
                FLUSH(p);
                return true;
        }
}




#endif /* UTILITIES_H_ */

