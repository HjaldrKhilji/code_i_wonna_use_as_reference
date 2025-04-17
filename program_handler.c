/*copyright 2024 Muneem. 
u can use it if u want but cant copy it.
*/
//todo 
//fix the size of allocations in shared memory
//make sure that keys of shared memory are in array that acts like stack by providing functions to do that
//also make sure that u empty the entire stack before ur program exits
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>
#include <unistd.h>
#include<errno.h>

#ifdef _WIN32
        #include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>

#elif __APPLE__

#include <sys/mman.h>
       #include <sys/stat.h>        /* For mode constants */
       #include <fcntl.h>      
//#elif __linux__
	#include <sys/shm.h>
#else
	#include <sys/mman.h>
       #include <sys/stat.h>        /* For mode constants */
       #include <fcntl.h>      

#include<limits.h>
//functions and macros that stores insides shared memory:
int  *options_selected;
int alignment_var;
struct INFO_OUTPUTS_FOR_2d_Proccessing{
int NUMBER_OF_OUTPUTS;
int key_of_outputs;
char **OUTPUT;
};






//input and processing linux based operating systems shared memory macros:

//input macros:
#define input_bulk_shmget(data_key,INITIAL_SIZE,INITIAL_SIZE_){INITIAL_SIZE_=(((((((MINIMUM_LIMIT_FOR_BASE_INPUT*sizeof(char))+(how_many_inputs*sizeof(char*))+(how_many_inputs*sizeof(int)))/alignment_var)+1))*alignment_var);\
INITIAL_SIZE=INITIAL_SIZE_;\    
data_key= shmget( IPC_PRIVATE, INITIAL_SIZE, IPC_CREAT | protection_for_all_memory );\
while(data_key==-1){\
fprintf(stderr, "\n error occured in shmget() function call\n");\
data_key = shmget( IPC_PRIVATE, INITIAL_SIZE, IPC_CREAT | protection_for_all_memory );\
}\
}
#define input_bulk_shmget_MINIMUM_OVERFLOW(data_key, INITIAL_SIZE,INITIAL_SIZE_ ){ shmdt((input));\
   shmctl( shmid_data, IPC_RMID, NULL );\
    INITIAL_SIZE =INITIAL_SIZE_* times_the_limit_reached;\
    data_key = shmget( IPC_PRIVATE, INITIAL_SIZE, IPC_CREAT | protection_for_all_memory );\
while(data_key==-1){\
fprintf(stderr, "\n error occured in shmget() function call\n");\
data_key = shmget( IPC_PRIVATE, INITIAL_SIZE, IPC_CREAT | protection_for_all_memory );\
}\
}

#define input_normal_shmget(data_key,INITIAL_SIZE,INITIAL_SIZE_){ INITIAL_SIZE_=((((((MINIMUM_LIMIT_FOR_BASE_INPUT*sizeof(char)))/alignment_var)+1))*alignment_var);\
    INITIAL_SIZE=INITIAL_SIZE_;\
    data_key= shmget( IPC_PRIVATE, INITIAL_SIZE, IPC_CREAT | protection_for_all_memory );\
 while(data_key==-1){\
fprintf(stderr, "\n error occured in shmget() function call\n");\
data_key = shmget( IPC_PRIVATE, INITIAL_SIZE, IPC_CREAT | protection_for_all_memory );\
}}
#define input_normal_shmget_MINIMUM_OVERFLOW(data_key,INITIAL_SIZE,INITIAL_SIZE_){shmdt((input));\
   shmctl( shmid_data, IPC_RMID, NULL );\
     INITIAL_SIZE =INITIAL_SIZE_* times_the_limit_reached;\
    data_key = shmget( IPC_PRIVATE, INITIAL_SIZE, IPC_CREAT | protection_for_all_memory );\
   while(data_key==-1){\
fprintf(stderr, "\n error occured in shmget() function call\n");\
data_key = shmget( IPC_PRIVATE, INITIAL_SIZE, IPC_CREAT | protection_for_all_memory );\
}\
}




#define input_bulk_shmat(data_key, data_destination){(data_destination) = (char*)shmat( shmid_data, NULL, 0 );\
 while(data_destination==(void)-1){\
fprintf(stderr, "\nerror occured in the shmat function\n");\
(data_destination) = (char*)shmat( shmid_data, NULL, 0 );\
}\
}
#define input_bulk_shmat_MINUIMUM_OVERFLOW(data_key, data_destination){\
 (data_destination) =(char*) shmat( shmid_data, NULL, 0 ); \
    while(data_destination==(void)-1){\
fprintf(stderr, "\nerror occured in the shmat function\n");\
 (data_destination) =(char*) shmat( shmid_data, NULL, 0 ); \
}\
}

#define input_normal_shmat(data_key,data_destination){ (data_destination) = (char*)shmat( shmid_data, NULL, 0 );\
     while(data_destination==(void)-1){\
fprintf(stderr, "\nerror occured in the shmat function\n");\
(data_destination) = (char*)shmat( shmid_data, NULL, 0 );\
} }
#define input_normal_shmat_MINIMUM_OVERFLOW(data_key,data_destination){(data_destination) = (char*)shmat( shmid_data, NULL, 0 );\
     while(data_destination==(void)-1){\
fprintf(stderr, "\nerror occured in the shmat function\n");\
(data_destination) = (char*)shmat( shmid_data, NULL, 0 );\
}\ 
}


//processing macros:
#define error_limit_before_telling_user 100
#define bulk_shmget_macro(shm_data) {  
 shmid_data = shmget( IPC_PRIVATE,((((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)*the_amount_of_sub_strings_needed)+((sizeof(char)*the_size_of_bulk)+((sizeof(char*)+sizeof(char))*the_amount_of_sub_strings_needed)))/alignment_var)+1))*alignment_var), IPC_CREAT | protection_for_all_memory);\
  while (shmid_data ==-1){\
fprintf(stderr, "\nshmid call failed, gonna try again\n");\
 shmid_data = shmget( IPC_PRIVATE,((((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)*the_amount_of_sub_strings_needed)+((sizeof(char)*the_size_of_bulk)+((sizeof(char*)+sizeof(char))*the_amount_of_sub_strings_needed)))/alignment_var)+1))*alignment_var), IPC_CREAT | protection_for_all_memory);\
}}

#define normal_shmget_macro(shm_data) { shmid_data = shmget( IPC_PRIVATE,((((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)+((sizeof(char)*size_of_input)+(((sizeof(char)+sizof(char*))*the_amount_of_sub_strings_needed)))/alignment_var)+1))*alignment_var)), IPC_CREAT | protection_for_all_memory );\
  while (shmid_data ==-1){\
fprintf(stderr, "\nshmid call failed, gonna try again\n");\
shmid_data = shmget( IPC_PRIVATE,((((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)+((sizeof(char)*size_of_input)+(((sizeof(char)+sizof(char*))*the_amount_of_sub_strings_needed)))/alignment_var)+1))*alignment_var)), IPC_CREAT | protection_for_all_memory );\
}  }
#define bulk_shmget_macro_pre_allocated(shm_data) {  int shmid_data = shmget( IPC_PRIVATE,((((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)*the_amount_of_sub_strings_needed)+(sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)*the_amount_of_sub_strings_needed_sub))+(sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing*)*the_amount_of_sub_strings_needed)+((sizeof(char)*size_bulk_data*2)+((sizeof(char*)+sizeof(char))*the_amount_of_sub_strings_needed)+((sizeof(char*)+sizeof(char)*the_amount_of_sub_strings_needed_sub))))/alignment_var)+1))*alignment_var), IPC_CREAT | protection_for_all_memory);\
   while (shmid_data ==-1){\
fprintf(stderr, "\nshmid call failed, gonna try again\n");\
 int shmid_data = shmget( IPC_PRIVATE,((((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)*the_amount_of_sub_strings_needed)+(sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)*the_amount_of_sub_strings_needed_sub))+(sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing*)*the_amount_of_sub_strings_needed)+((sizeof(char)*size_bulk_data*2)+((sizeof(char*)+sizeof(char))*the_amount_of_sub_strings_needed)+((sizeof(char*)+sizeof(char)*the_amount_of_sub_strings_needed_sub))))/alignment_var)+1))*alignment_var), IPC_CREAT | protection_for_all_memory);\
  }    }
#define normal_shmget_macro_pre_allocated(shm_data) {int shmid_data = shmget( IPC_PRIVATE,((((((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)*the_amount_of_sub_strings_needed_sub)+(sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing))+((sizeof(char)*size_of_input*2)+((((sizeof(char)+sizeof(char*))*the_amount_of_sub_strings_needed)))+(((sizeof(char)+sizof(char*))*the_amount_of_sub_strings_needed_sub)))/alignment_var)+1))*alignment_var)), IPC_CREAT | protection_for_all_memory );\
   while (shmid_data ==-1){\
fprintf(stderr, "\nshmid call failed, gonna try again\n");\
int shmid_data = shmget( IPC_PRIVATE,((((((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)*the_amount_of_sub_strings_needed_sub)+(sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing))+((sizeof(char)*size_of_input*2)+((((sizeof(char)+sizeof(char*))*the_amount_of_sub_strings_needed)))+(((sizeof(char)+sizof(char*))*the_amount_of_sub_strings_needed_sub)))/alignment_var)+1))*alignment_var)), IPC_CREAT | protection_for_all_memory );\
  }     }

#define bulk_shmat_macro(shm_data,INFO_OUTPUTS) { INFO_OUTPUTS= (struct INFO_OUTPUTS_FOR_2d_Proccessing*)(shmat( shmid_data, NULL, 0 ));\
  while( INFO_OUTPUTS==(void*)-1){\
INFO_OUTPUTS= (struct INFO_OUTPUTS_FOR_2d_Proccessing*)(shmat( shmid_data, NULL, 0 ));\
fprintf(stderr, "\nshmat call failed, gonna try again\n");\
\
}\
}


#define normal_shmat_macro(shm_data,INFO_OUTPUTS) {   INFO_OUTPUTS= (struct INFO_OUTPUTS_FOR_2d_Proccessing*)(shmat( shmid_data, NULL, 0 ));\
     while( INFO_OUTPUTS==(void*)-1){\
 INFO_OUTPUTS= (struct INFO_OUTPUTS_FOR_2d_Proccessing*)(shmat( shmid_data, NULL, 0 ));\  
fprintf(stderr, "\nshmat call failed, gonna try again\n");\
\
} }
#define bulk_shmat_macro_pre_allocated(shm_data) { INFO_OUTPUTS= (struct INFO_OUTPUTS_FOR_2d_Proccessing*)(shmat( shmid_data, NULL, 0 ));\
     while( INFO_OUTPUTS==(void*)-1){\
 INFO_OUTPUTS= (struct INFO_OUTPUTS_FOR_2d_Proccessing*)(shmat( shmid_data, NULL, 0 ));\  
fprintf(stderr, "\nshmat call failed, gonna try again\n");\
\
}}
#define normal_shmat_macro_pre_allocated(shm_data) {INFO_OUTPUTS= (struct INFO_OUTPUTS_FOR_2d_Proccessing*)(shmat( shmid_data, NULL, 0 ));\
     while( INFO_OUTPUTS==(void*)-1){\
 INFO_OUTPUTS= (struct INFO_OUTPUTS_FOR_2d_Proccessing*)(shmat( shmid_data, NULL, 0 ));\  
fprintf(stderr, "\nshmat call failed, gonna try again\n");\
}\
    (((*INFO_OUTPUTS).key_of_outputs))=shmid_data;\
    ((*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)=0;\
    ((*INFO_OUTPUTS).OUTPUT)=(char**)(INFO_OUTPUTS+1);\
}}

//u can replace 1000 in i=1000 with what ever u want in the macros above because it defines the amount of errors that have to occur in order for the error to be outputed to the stderr file descriptor

//code-for-shared memory-macros-for-linux-has-ended-on-this-line-of-the-code


//input and processing for unix based operating systems shared memory macros:

//input macros:
void input_bulk_shm_open_AND_set(int *data_key,int *INITIAL_SIZE,int *INITIAL_SIZE_){int _INITIAL_SIZE_=(((((((MINIMUM_LIMIT_FOR_BASE_INPUT*sizeof(char))+(how_many_inputs*sizeof(char*))+(how_many_inputs*sizeof(int)))/alignment_var)+1))*alignment_var);
int _INITIAL_SIZE=INITIAL_SIZE_;

int _data_key= ;
 for(long int i=0, x=0;shmid_data==-1; i++){
  +data_key = shmget( IPC_PRIVATE, INITIAL_SIZE, IPC_CREAT | protection_for_all_memory );
if(i==1000){
x++;
fprintf(stderr,"\ntried making shmget key %d times, but failed all of them, the reason for error is:\n",i*x);
perror("");
fprintf(stderr,"\nlets hope this is a coincedance\n");
i=0;}
}
}
#define input_bulk_shmget_MINIMUM_OVERFLOW(data_key, INITIAL_SIZE,INITIAL_SIZE_ ){ shmdt((input));\
   shmctl( shmid_data, IPC_RMID, NULL );\
    INITIAL_SIZE =INITIAL_SIZE_* times_the_limit_reached;\
    data_key = shmget( IPC_PRIVATE, INITIAL_SIZE, IPC_CREAT | protection_for_all_memory );\
    for(long int i=0, x=0;shmid_data==-1; i++){\
 data_key= shmget( IPC_PRIVATE, INITIAL_SIZE, IPC_CREAT | protection_for_all_memory );\
if(i==1000){\
x++;\
fprintf(stderr,"\ntried making shmget key %d times, but failed all of them, the reason for error is:\n",i*x);\
perror("");\
fprintf(stderr,"\nlets hope this is a coincedance\n");\
i=0;\
}\
}\
}

#define input_normal_shmget(data_key,INITIAL_SIZE,INITIAL_SIZE_){ INITIAL_SIZE_=((((((MINIMUM_LIMIT_FOR_BASE_INPUT*sizeof(char)))/alignment_var)+1))*alignment_var);\
    INITIAL_SIZE=INITIAL_SIZE_;\
    data_key= shmget( IPC_PRIVATE, INITIAL_SIZE, IPC_CREAT | protection_for_all_memory );\
 for(long int i=0, x=0;shmid_data==-1; i++){\
   data_key= shmget( IPC_PRIVATE, INITIAL_SIZE, IPC_CREAT | protection_for_all_memory );\
if(i==1000){\
x++;\
fprintf(stderr,"\ntried making pipes %d times, but failed all of them, the reason for error is:\n",i*x);\
perror("");\
fprintf(stderr,"\nlets hope this is a coincedance\n");\
i=0;}}}
#define input_normal_shmget_MINIMUM_OVERFLOW(data_key,INITIAL_SIZE,INITIAL_SIZE_){shmdt((input));\
   shmctl( shmid_data, IPC_RMID, NULL );\
     INITIAL_SIZE =INITIAL_SIZE_* times_the_limit_reached;\
    data_key = shmget( IPC_PRIVATE, INITIAL_SIZE, IPC_CREAT | protection_for_all_memory );\
    for(long int i=0, x=0;shmid_data==-1; i++){\
 data_key = shmget( IPC_PRIVATE, INITIAL_SIZE, IPC_CREAT | protection_for_all_memory );\
if(i==1000){\
x++;\
fprintf(stderr,"\ntried making pipes %d times, but failed all of them, the reason for error is:\n",i*x);\
perror("");\
fprintf(stderr,"\nlets hope this is a coincedance\n");\
i=0;\
}\
}\
}




#define input_bulk_shmat(data_key, data_destination){(data_destination) = (char*)shmat( shmid_data, NULL, 0 );\
     for(long int i=0, x=0;(input)==(void*)(-1); i++){\
 (data_destination) = (char*)shmat( shmid_data, NULL, 0 );\
if(i==1000){\
x++;\
fprintf(stderr,"\ntried assigning memory using shmget key %d times, but failed all of them, the reason for error is:\n",i*x);\
perror("");\
fprintf(stderr,"\nlets hope this is a coincedance\n");\
i=0;\
}\
}\
}
#define input_bulk_shmat_MINUIMUM_OVERFLOW(data_key, data_destination){\
 (data_destination) =(char*) shmat( shmid_data, NULL, 0 ); \
      for(long int i=0, x=0;(input)==(void*)(-1); i++){\
 (data_destination) = (char*)shmat( shmid_data, NULL, 0 );\
if(i==1000){\
x++;\
fprintf(stderr,"\ntried assigned shared memory using shmat %d times, but failed all of them, the reason for error is:\n",i*x);\
perror("");\
fprintf(stderr,"\nlets hope this is a coincedance\n");\
i=0;\
}\
}\
}

#define input_normal_shmat(data_key,data_destination){ (data_destination) = (char*)shmat( shmid_data, NULL, 0 );\
     for(long int i=0, x=0;(input)==(void*)(-1); i++){\
 (data_destination) = (char*)shmat( shmid_data, NULL, 0 );\
if(i==1000){\
x++;\
fprintf(stderr,"\ntried assigning memory using shmget key %d times, but failed all of them, the reason for error is:\n",i*x);\
perror("");\
fprintf(stderr,"\nlets hope this is a coincedance\n");\
i=0;\
}\
}   }
#define input_normal_shmat_MINIMUM_OVERFLOW(data_key,data_destination){(data_destination) =(char*) shmat( shmid_data, NULL, 0 ); \
      for(long int i=0, x=0;(input)==(void*)(-1); i++){\
 (data_destination) = (char*)shmat( shmid_data, NULL, 0 );\
if(i==1000){\
x++;\
fprintf(stderr,"\ntried making pipes %d times, but failed all of them, the reason for error is:\n",i*x);\
perror("");\
fprintf(stderr,"\nlets hope this is a coincedance\n");\
i=0;\
}\
}\  
}


//processing macros:
#define error_limit_before_telling_user 100
#define bulk_shmget_macro(shm_data) {   shmid_data = shmget( IPC_PRIVATE,((((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)*the_amount_of_sub_strings_needed)+((sizeof(char)*the_size_of_bulk)+((sizeof(char*)+sizeof(char))*the_amount_of_sub_strings_needed)))/alignment_var)+1))*alignment_var), IPC_CREAT | protection_for_all_memory);\
  for(long int i=0, x=0;(shmid_data)==(-1); i++){\
shmid_data = shmget( IPC_PRIVATE,((((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)*the_amount_of_sub_strings_needed)+((sizeof(char)*the_size_of_bulk)+((sizeof(char*)+sizeof(char))*the_amount_of_sub_strings_needed)))/alignment_var)+1))*alignment_var), IPC_CREAT | protection_for_all_memory);\
if(i==1000){\
x++;\
fprintf(stderr,"\ntried getting shared memory key %d times, but failed all of them, the reason for error is:\n",i*x);\
perror("");\
fprintf(stderr,"\nlets hope this is a coincedance\n");\
i=0;\
}\
}   }

#define normal_shmget_macro(shm_data) { shmid_data = shmget( IPC_PRIVATE,((((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)+((sizeof(char)*size_of_input)+(((sizeof(char)+sizof(char*))*the_amount_of_sub_strings_needed)))/alignment_var)+1))*alignment_var)), IPC_CREAT | protection_for_all_memory );\
  for(long int i=0, x=0;(shmid_data)==(-1); i++){shmid_data = shmget( IPC_PRIVATE,((((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)+((sizeof(char)*size_of_input)+(((sizeof(char)+sizof(char*))*the_amount_of_sub_strings_needed)))/alignment_var)+1))*alignment_var)), IPC_CREAT | protection_for_all_memory );\
if(i==1000){\
x++;\
fprintf(stderr,"\ntried getting shared memory key %d times, but failed all of them, the reason for error is:\n",i*x);\
perror("");\
fprintf(stderr,"\nlets hope this is a coincedance\n");\
i=0;\
}\
}    }
#define bulk_shmget_macro_pre_allocated(shm_data) {  int shmid_data = shmget( IPC_PRIVATE,((((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)*the_amount_of_sub_strings_needed)+(sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)*the_amount_of_sub_strings_needed_sub))+(sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing*)*the_amount_of_sub_strings_needed)+((sizeof(char)*size_bulk_data*2)+((sizeof(char*)+sizeof(char))*the_amount_of_sub_strings_needed)+((sizeof(char*)+sizeof(char)*the_amount_of_sub_strings_needed_sub))))/alignment_var)+1))*alignment_var), IPC_CREAT | protection_for_all_memory);\
  for(long int i=0, x=0;(shmid_data)==(-1); i++){shmid_data = shmget( IPC_PRIVATE,((((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)*the_amount_of_sub_strings_needed)+(sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)*the_amount_of_sub_strings_needed_sub))+((sizeof(char)*size_bulk_data*2)+((sizeof(char*)+sizeof(char))*the_amount_of_sub_strings_needed)+(sizeof(char**)*amount_of_input_strings)+((sizeof(char*)+sizeof(char)*the_amount_of_sub_strings_needed_sub))))/alignment_var)+1))*alignment_var), IPC_CREAT | protection_for_all_memory);\
if(i==1000){\
x++;\
fprintf(stderr,"\ntried getting shared memory key %d times, but failed all of them, the reason for error is:\n",i*x);\
perror("");\
fprintf(stderr,"\nlets hope this is a coincedance\n");\
i=0;}}    }
#define normal_shmget_macro_pre_allocated(shm_data) {int shmid_data = shmget( IPC_PRIVATE,((((((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)*the_amount_of_sub_strings_needed_sub)+(sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing))+((sizeof(char)*size_of_input*2)+((((sizeof(char)+sizeof(char*))*the_amount_of_sub_strings_needed)))+(((sizeof(char)+sizof(char*))*the_amount_of_sub_strings_needed_sub)))/alignment_var)+1))*alignment_var)), IPC_CREAT | protection_for_all_memory );\
  for(long int i=0, x=0;(shmid_data)==(-1); i++){shmid_data = shmget( IPC_PRIVATE,((((((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)*the_amount_of_sub_strings_needed_sub)+(sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing))+((sizeof(char)*size_of_input*2)+((((sizeof(char)+sizeof(char*))*the_amount_of_sub_strings_needed)))+(((sizeof(char)+sizof(char*))*the_amount_of_sub_strings_needed_sub)))/alignment_var)+1))*alignment_var)), IPC_CREAT | protection_for_all_memory );\
if(i==1000){\
x++;\
fprintf(stderr,"\ntried getting shared memory key %d times, but failed all of them, the reason for error is:\n",i*x);\
perror("");\
fprintf(stderr,"\nlets hope this is a coincedance\n");\
i=0;\
}\
}    }

#define bulk_shmat_macro(shm_data,INFO_OUTPUTS) { INFO_OUTPUTS= (struct INFO_OUTPUTS_FOR_2d_Proccessing*)(shmat( shmid_data, NULL, 0 ));\
   for(long int i=0, x=0;(INFO_OUTPUTS)==(void*)(-1); i++){\
     INFO_OUTPUTS= (struct INFO_OUTPUTS_FOR_2d_Proccessing*)(shmat( shmid_data, NULL, 0 ));\   
if(i==1000){\
x++;\
fprintf(stderr,"\ntried assigning shared memory %d times, but failed all of them, the reason for error is:\n",i*x);\
perror("");\
fprintf(stderr,"\nlets hope this is a coincedance\n");\
i=0;\
}}}}


#define normal_shmat_macro(shm_data,INFO_OUTPUTS) {   INFO_OUTPUTS= (struct INFO_OUTPUTS_FOR_2d_Proccessing*)(shmat( shmid_data, NULL, 0 ));\
   for(long int i=0, x=0;(INFO_OUTPUTS)==(void*)(-1); i++){\
     INFO_OUTPUTS= (struct INFO_OUTPUTS_FOR_2d_Proccessing*)(shmat( shmid_data, NULL, 0 ));\   
if(i==1000){\
x++'\
fprintf(stderr,"\ntried assigning shared memory %d times, but failed all of them, the reason for error is:\n",i*x);\
perror("");\
fprintf(stderr,"\nlets hope this is a coincedance\n");\
i=0;\
}}  }
#define bulk_shmat_macro_pre_allocated(shm_data) { INFO_OUTPUTS= (struct INFO_OUTPUTS_FOR_2d_Proccessing*)(shmat( shmid_data, NULL, 0 ));\  
   for(long int i=0, x=0;(INFO_OUTPUTS)==(void*)(-1); i++){\
     INFO_OUTPUTS= (struct INFO_OUTPUTS_FOR_2d_Proccessing*)(shmat( shmid_data, NULL, 0 ));\   
if(i==1000){\
x++;\
fprintf(stderr,"\ntried assigning shared memory %d times, but failed all of them, the reason for error is:\n",i*x);\
perror("");\
fprintf(stderr,"\nlets hope this is a coincedance\n");\
i=0;\
}}}}
#define normal_shmat_macro_pre_allocated(shm_data) {INFO_OUTPUTS= (struct INFO_OUTPUTS_FOR_2d_Proccessing*)(shmat( shmid_data, NULL, 0 ));\
   for(long int i=0, x=0;(INFO_OUTPUTS)==(void*)(-1); i++){\
     INFO_OUTPUTS= (struct INFO_OUTPUTS_FOR_2d_Proccessing*)(shmat( shmid_data, NULL, 0 ));\
if(i==1000){\
x++;\
fprintf(stderr,"\ntried assigning shared memory %d times, but failed all of them, the reason for error is:\n",i*x);\
perror("");\
fprintf(stderr,"\nlets hope this is a coincedance\n");\
i=0;\
}}\
    (((*INFO_OUTPUTS).key_of_outputs))=shmid_data;\
    ((*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)=0;\
    ((*INFO_OUTPUTS).OUTPUT)=(char**)(INFO_OUTPUTS+1);\
}}

//u can replace 1000 in i=1000 with what ever u want in the macros above because it defines the amount of errors that have to occur in order for the error to be outputed to the stderr file descriptor


void process_input_into_parts_bulk(char **input, int amount_of_input_strings, struct INFO_OUTPUTS_FOR_2d_Proccessing *INFO_OUTPUTS,  long int *size_of_input,char *divider, int protection_for_all_memory){
 long long int the_size_of_bulk=0;
for(int counter=0;size_of_input[counter]!=LONG_MAX;counter++){
the_size_of_bulk+=size_of_input[counter];
}
 long int the_amount_of_sub_strings_needed=0;
long int the_amount_of_sub_strings_needed_for_each_input_string[amount_of_input_strings];
 //the code before is important cuz it saves a lot of shit, and by a lot i mean a lot
 for(int counter=0; counter< amount_of_input_strings;counter++){
 the_amount_of_sub_strings_needed_for_each_input_string[counter]=0;
 input_local=input[counter];
 for(long int i = 0, j=0, c=0;i<size_of_input[counter];i++){
   if(input_local[i]== divider[counter]&&!(j||c)){
	  the_amount_of_sub_strings_needed++; 
	  the_amount_of_sub_strings_needed_for_each_input_string[counter]++;
   }
    if(input_local[i]=='\''){
         if(j==1){
            j=0;
        
    }
         else{
            if(c==0){
            j=1;
            }
        }
    }
    if(input_local[i]=='\"'){
         if(c==1){
            c=0;
        
    }
         else{
            if(j==0){
            c=1;
            }
        }
    }



 
 }
 
 }



if(protection_for_all_memory!=-1){
	 

    printf("permissions of my shared memory is %d\n", protection_for_all_memory);
int shmid_date;
#ifdef _WIN32

#elif __APPLE__

#elif __linux__
bulk_shmget_macro(shmid_date);

#else
    



#ifdef _WIN32

#elif __APPLE__

#elif __linux__
    bulk_shmat_macro(shmid_date,INFO_OUTPUTS);
  
#else

   
else{}
long int char_size=0;
long  int char_pointer_size=0;

for(long int counter=0; counter<amount_of_input_strings;counter++){
   
    (((INFO_OUTPUTS[counter]).key_of_outputs))=shmid_data;
 
    int local_number_of_output=0;//local variable for faster speed and to avoid pointer
    ((INFO_OUTPUTS[counter]).OUTPUT)=((char)(((char**)(INFO_OUTPUTS+amount_of_input_strings))+char_pointer_size))+char_size;
    char_pointer_size+=the_amount_of_sub_strings_needed_for_each_input_string[counter];
    char **local_pointer_for_string=((INFO_OUTPUTS[counter]).OUTPUT);//faster speed due to localization of a memory location
    int i=0;
    for(int e=0,c=0,j=0;;i++,e++){
     if(size_of_input==i){
        break;
    }
  
    if(input[i]== divider&&!(j||c)){
       	
        
    local_pointer_for_string[local_number_of_output]=(local+the_amount_of_sub_strings_needed_for_each_input_string[counter]);
    printf("\ni and e before memcpy are i:%d, e:%d,     \n	the full address is %p, the base address is %p, \nthe base_add_base_size address is %p, the base plus charactor pointers address is %p, the artifical+compulsary boundary is %p, the total value added to base is %p\n",
		       i,e, local_pointer_for_string[local_number_of_output], 
		       INFO_OUTPUTS[counter], (INFO_OUTPUTS[counter]+1), (local_pointer_for_string[local_number_of_output])+size_of_input,
		       (((u_int8_t*)(INFO_OUTPUTS))+(int)(((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)+
				       (((sizeof(char*)+sizeof(char))*size_of_input)+sizeof(char)))/alignment_var)+1))*alignment_var)),
		        (u_int8_t*)((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)+
				       (((sizeof(char*)+sizeof(char))*size_of_input)+sizeof(char)))/alignment_var)+1)*alignment_var));
       	
	printf("\n the new string will be at:%p and the null terminator will be at %p\n",(( ((*INFO_OUTPUTS).OUTPUT))[( (*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)]), &( (((*INFO_OUTPUTS).OUTPUT))[( (*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)][e]));
	printf("\nthe copying offset is %d and the limit is %d\n", (i-e), size_of_input);
	local_pointer_for_string[local_number_of_output][e]='\0';
	memcpy((void*)local_pointer_for_string[local_number_of_output],(void*)(input+(i-e)),((e)*sizeof(char)));
        	

        printf("partially more constructed string is %s\n", (((*INFO_OUTPUTS).OUTPUT))[( (*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)]);	
       	e=-1;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");	
	( (*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)++;
    }
    if(input[i]=='\''){
         if(j==1){
            j=0;
        
    }
         else{
            if(c==0){
            j=1;
            }
        }
    }
    if(input[i]=='\"'){
         if(c==1){
            c=0;
        
    }
         else{
            if(j==0){
            c=1;
            }
        }
    }


   }
char_size+=i;
INFO_OUTPUTS[counter].NUMBER_OF_OUTPUTS=local_number_of_output;
 }

}

void process_input_into_parts(char *input,  struct INFO_OUTPUTS_FOR_2d_Proccessing *INFO_OUTPUTS, long int size_of_input,char divider, int protection_for_all_memory){
  if(input[0]=='\0'){fprintf(stderr,"\n(*input to function empty please write something in it\n");}
 int the_amount_of_sub_strings_needed=0;
 //the code before is important cuz it saves a lot of shit, and by a lot i mean a lot
 
 for(long int i =0;i<size_of_input;i++){
   if(input[i]== divider&&!(j||c)){
	  the_amount_of_sub_strings_needed++; 
   }
    if(input[i]=='\''){
         if(j==1){
            j=0;
        
    }
         else{
            if(c==0){
            j=1;
            }
        }
    }
    if(input[i]=='\"'){
         if(c==1){
            c=0;
        
    }
         else{
            if(j==0){
            c=1;
            }
        }
    }



 
 }
 
 





	 
if(protection_for_all_memory!=-1){
    printf("permissions of my shared memory is %d\n", protection_for_all_memory);
int shmid_date;
#ifdef _WIN32

#elif __APPLE__

#elif __linux__
normal_shmget_macro(shmid_date);
#else
    



#ifdef _WIN32

#elif __APPLE__

#elif __linux__
normal_shmat_macro(shmid_date,INFO_OUTPUTS);
#else
    
  



   
 
    (((*INFO_OUTPUTS).key_of_outputs))=shmid_data;
    ((*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)=0; 
    
    ((*INFO_OUTPUTS).OUTPUT)=(char**)(INFO_OUTPUTS+1);
}
else{}

    for(long int i=0, e=0,c=0,j=0;;i++, e++){
     if(size_of_input==i){
        break;
    }
  
    if(input[i]== divider&&!(j||c)){
       char **local_sub_string=((( ((*INFO_OUTPUTS).OUTPUT))[( (*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)]);
        
       	*local_sub_string=((((char*)(INFO_OUTPUTS+1))+size_of_input)+((i-e)));
        printf("\ni and e before memcpy are i:%d, e:%d,     \n	the full address is %p, the base address is %p, \nthe base_add address is %p, the base plus charactor pointers address is %p, the artifical+compulsary boundary is %p, the total value added to base is %p\n",
		       i,e, (((*INFO_OUTPUTS).OUTPUT))[( (*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)], 
		       (INFO_OUTPUTS), (INFO_OUTPUTS+1), ((char*)(INFO_OUTPUTS+1))+size_of_input,
		       (((u_int8_t*)(INFO_OUTPUTS))+(int)(((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)+
				       (((sizeof(char*)+sizeof(char))*size_of_input)+sizeof(char)))/alignment_var)+1))*alignment_var)),
		        (u_int8_t*)((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)+
       				       (((sizeof(char*)+sizeof(char))*size_of_input)+sizeof(char)))/alignment_var)+1)*alignment_var));
	
	printf("\n the new string will be at:%p and the null terminator will be at %p\n",(( ((*INFO_OUTPUTS).OUTPUT))[( (*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)]), &( (((*INFO_OUTPUTS).OUTPUT))[( (*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)][e]));
	printf("\nthe copying offset is %d and the limit is %d\n", (i-e), size_of_input);
memcpy(*local_sub_string, input[i-e], e*sizeof(char));
	(*local_sub_string)[e]='\0';

        printf("partially more constructed string is %s\n", (((*INFO_OUTPUTS).OUTPUT))[( (*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)]);	
       	e=-1;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");	
	( (*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)++;
    }
    if(input[i]=='\''){
         if(j==1){
            j=0;
        
    }
         else{
            if(c==0){
            j=1;
            }
        }
    }
    if(input[i]=='\"'){
         if(c==1){
            c=0;
        
    }
         else{
            if(j==0){
            c=1;
            }
        }
    }


   }


 
}

void process_input_into_parts_bulk_pre_allocated(char **input, int amount_of_input_strings, struct INFO_OUTPUTS_FOR_2d_Proccessing *INFO_OUTPUTS,struct INFO_OUTPUTS_FOR_2d_Proccessing **INFO_OUTPUTS_sub,  int *size_of_input,char *divider, char *divider_2, int protection_for_all_memory){

 long int the_amount_of_sub_strings_needed=0;
 long int the_amount_of_sub_strings_needed_sub=0;
 long long int size_bulk_data=0;
for(int counter=0;size_of_input[counter]!=LONG_MAX;counter++){
the_size_of_bulk+=size_of_input[counter];
}
long int the_amount_of_sub_strings_needed_for_each_input_string[amount_of_input_strings];
 //the code before is important cuz it saves a lot of shit, and by a lot i mean a lot
 for(int counter=0; counter< amount_of_input_strings;counter++){
 the_amount_of_sub_strings_needed_for_each_input_string[counter]=0;
 input_local=input[counter];
 for(long int i =0, j=0, c=0;i<size_of_input[counter];i++){
   if(input_local[i]== divider[counter]&&!(j||c)){
	  the_amount_of_sub_strings_needed++; 
	  the_amount_of_sub_strings_needed_for_each_input_string[counter]++;
   }

   if(input_local[i]== divider_2[counter]&&!(j||c)){
	  the_amount_of_sub_strings_needed_sub++; 
   }

    if(input_local[i]=='\''){
         if(j==1){
            j=0;
        
    }
         else{
            if(c==0){
            j=1;
            }
        }
    }
    if(input_local[i]=='\"'){
         if(c==1){
            c=0;
        
    }
         else{
            if(j==0){
            c=1;
            }
        }
    }



 
 }
 
 }



if(protection_for_all_memory!=-1){
	 
int shmid_date;
#ifdef _WIN32

#elif __APPLE__

#elif __linux__
   bulk_shmget_macro_pre_allocated(shmid_date);
#else
 



#ifdef _WIN32

#elif __APPLE__

#elif __linux__
 bulk_shmat_macro_pre_allocated(shmid_date,INFO_OUTPUTS);
#else
   
    printf("permissions of my shared memory is %d\n", protection_for_all_memory);

else{}
long int char_size=0;
long  int char_pointer_size=0;
long  int char_pointer_size_sub=0;
INFO_OUTPUTS_sub=((struct INFO_OUTPUTS_FOR_2d_Proccessing*)(INFO_OUTPUTS+((((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)*the_amount_of_sub_strings_needed)+((sizeof(char)*the_size_of_bulk)+((sizeof(char*)+sizeof(char))*the_amount_of_sub_strings_needed)))));

for(long int counter=0; counter<amount_of_input_strings;counter++){

    (((INFO_OUTPUTS[counter]).key_of_outputs))=shmid_data;
 long int size_of_each_sub_string__[the_amount_of_sub_strings_needed_for_each_input_string[counter]];
    int local_number_of_output=0;//local variable for faster speed and to avoid pointer
    ((INFO_OUTPUTS[counter]).OUTPUT)=((char)(((char**)(INFO_OUTPUTS+amount_of_input_strings))+char_pointer_size))+char_size;
    char_pointer_size+=the_amount_of_sub_strings_needed_for_each_input_string[counter];
    char **local_pointer_for_string=((INFO_OUTPUTS[counter]).OUTPUT);//faster speed due to localization of a memory location
    int i=0;
    for(int e=0,c=0,j=0;;i++,e++){
     if(size_of_input==i){
        break;
    }
      for(int counter_for_divider=0;input[i]== divider_2[counter][counter_for_divider]&&!(j||c)){
char_pointer_size_sub++;
}
    if(input[i]== divider[counter]&&!(j||c)){
       	
        
    local_pointer_for_string[local_number_of_output]=(local+the_amount_of_sub_strings_needed_for_each_input_string[counter]);
    printf("\ni and e before memcpy are i:%d, e:%d,     \n	the full address is %p, the base address is %p, \nthe base_add_base_size address is %p, the base plus charactor pointers address is %p, the artifical+compulsary boundary is %p, the total value added to base is %p\n",
		       i,e, local_pointer_for_string[local_number_of_output], 
		       INFO_OUTPUTS[counter], (INFO_OUTPUTS[counter]+1), (local_pointer_for_string[local_number_of_output])+size_of_input,
		       (((u_int8_t*)(INFO_OUTPUTS))+(int)(((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)+
				       (((sizeof(char*)+sizeof(char))*size_of_input)+sizeof(char)))/alignment_var)+1))*alignment_var)),
		        (u_int8_t*)((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)+
				       (((sizeof(char*)+sizeof(char))*size_of_input)+sizeof(char)))/alignment_var)+1)*alignment_var));
       	
	printf("\n the new string will be at:%p and the null terminator will be at %p\n",(( ((*INFO_OUTPUTS).OUTPUT))[( (*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)]), &( (((*INFO_OUTPUTS).OUTPUT))[( (*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)][e]));
	printf("\nthe copying offset is %d and the limit is %d\n", (i-e), size_of_input);
if(counter==(amount_of_input_strings-1)){
	local_pointer_for_string[local_number_of_output][e]='\0';
INFO_OUTPUTS_sub=(struct INFO_OUTPUTS_FOR_2d_Proccessing*)(&(local_pointer_for_string[local_number_of_output][e+1]));}
	memcpy((void*)local_pointer_for_string[local_number_of_output],(void*)(input+(i-e)),((e)*sizeof(char)));

        	   size_of_each_sub_string__[((*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)]=e;


        printf("partially more constructed string is %s\n", (((*INFO_OUTPUTS).OUTPUT))[( (*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)]);	
       	e=-1;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");	
	 ((*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)++;
    }
    if(input[i]=='\''){
         if(j==1){
            j=0;
        
    }
         else{
            if(c==0){
            j=1;
            }
        }
    }
    if(input[i]=='\"'){
         if(c==1){
            c=0;
        
    }
         else{
            if(j==0){
            c=1;
            }
        }
    }


   }

char_size+=i;
INFO_OUTPUTS[counter].NUMBER_OF_OUTPUTS=local_number_of_output;
INFO_OUTPUTS_sub[counter]=(((char)(((struct struct INFO_OUTPUTS_FOR_2d_Proccessing)(struct INFO_OUTPUTS_FOR_2d_Proccessing**)(INFO_OUTPUT_sub+the_amount_of_sub_strings_needed)+char_pointer_size_sub))))+char_size+char_pointer_size_sub);
process_input_into_parts_bulk((INFO_OUTPUTS[counter]).OUTPUT, the_amount_of_sub_strings_needed_for_each_input_string[counter] ,INFO_OUTPUT_sub, size_of_each_sub_string__ ,divider_2[counter], -1);
 }

}


void process_input_into_parts_pre_allocated(char *input,  struct INFO_OUTPUTS_FOR_2d_Proccessing *INFO_OUTPUTS,struct INFO_OUTPUTS_FOR_2d_Proccessing *INFO_OUTPUTS_sub_processed, long  int size_of_input,char divider,char *divider_2, int protection_for_all_memory){
  if(input[0]=='\0'){fprintf(stderr,"\n(*input to function empty please write something in it\n");}
 int the_amount_of_sub_strings_needed=0;
 int the_amount_of_sub_strings_needed_sub=0;
 
 //the code before is important cuz it saves a lot of shit, and by a lot i mean a lot
 
 for(long int i =0;i<size_of_input;i++){
   if(input[i]== divider&&!(j||c)){
	  the_amount_of_sub_strings_needed++; 
   }
   if(input[i]== divider_2[the_amount_of_sub_strings_needed]&&!(j||c)){
	  the_amount_of_sub_strings_needed_sub++; 
   }
    if(input[i]=='\''){
         if(j==1){
            j=0;
        
    }
         else{
            if(c==0){
            j=1;
            }
        }
    }
    if(input[i]=='\"'){
         if(c==1){
            c=0;
        
    }
         else{
            if(j==0){
            c=1;
            }
        }
    }



 
 }
 int size_of_each_sub_string[the_amount_of_sub_strings_needed];
 





	 
if(protection_for_all_memory!=-1){

    printf("permissions of my shared memory is %d\n", protection_for_all_memory);

   int shmid_date;
#ifdef _WIN32

#elif __APPLE__

#elif __linux__
normal_shmget_macro_pre_allocated(shmid_date);
#else
    



#ifdef _WIN32

#elif __APPLE__

#elif __linux__
    normal_shmat_macro_pre_allocated(shmid_date,INFO_OUTPUTS);
#else

  
else{}

    for(long int i=0, e=0,c=0,j=0;;i++, e++){
     if(size_of_input==i){
        break;
    }
  
    if(input[i]== divider&&!(j||c)){
       char **local_sub_string=((( ((*INFO_OUTPUTS).OUTPUT))[( (*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)]);
        
       	*local_sub_string=((((char*)(INFO_OUTPUTS+1))+size_of_input)+((i-e)));
        printf("\ni and e before memcpy are i:%d, e:%d,     \n	the full address is %p, the base address is %p, \nthe base_add address is %p, the base plus charactor pointers address is %p, the artifical+compulsary boundary is %p, the total value added to base is %p\n",
		       i,e, (((*INFO_OUTPUTS).OUTPUT))[( (*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)], 
		       (INFO_OUTPUTS), (INFO_OUTPUTS+1), ((char*)(INFO_OUTPUTS+1))+size_of_input,
		       (((u_int8_t*)(INFO_OUTPUTS))+(int)(((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)+
				       (((sizeof(char*)+sizeof(char))*size_of_input)+sizeof(char)))/alignment_var)+1))*alignment_var)),
		        (u_int8_t*)((((sizeof(struct INFO_OUTPUTS_FOR_2d_Proccessing)+
       				       (((sizeof(char*)+sizeof(char))*size_of_input)+sizeof(char)))/alignment_var)+1)*alignment_var));
	
	printf("\n the new string will be at:%p and the null terminator will be at %p\n",(( ((*INFO_OUTPUTS).OUTPUT))[( (*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)]), &( (((*INFO_OUTPUTS).OUTPUT))[( (*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)][e]));
	printf("\nthe copying offset is %d and the limit is %d\n", (i-e), size_of_input);
memcpy(*local_sub_string, input[i-e], e*sizeof(char));
	(*local_sub_string)[e]='\0';
size_of_each_sub_string[(*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)]=e;
//this discludes the null terminator as planned
INFO_OUTPUTS_sub_processed=(struct INFO_OUTPUTS_FOR_2d_Proccessing*)(&((*local_sub_string)[e+1]));
        printf("partially more constructed string is %s\n", (((*INFO_OUTPUTS).OUTPUT))[( (*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)]);	
       	e=-1;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");	
	( (*INFO_OUTPUTS).NUMBER_OF_OUTPUTS)++;
    }
    if(input[i]=='\''){
         if(j==1){
            j=0;
        
    }
         else{
            if(c==0){
            j=1;
            }
        }
    }
    if(input[i]=='\"'){
         if(c==1){
            c=0;
        
    }
         else{
            if(j==0){
            c=1;
            }
        }
    }


   }

process_input_into_parts_bulk(
    ((*INFO_OUTPUTS).OUTPUT), 	  the_amount_of_sub_strings_needed, INFO_OUTPUTS_sub_processed, size_of_each_sub_string ,divider_2, -1);

 
}

/*#define size_of_all_three_dimension_structures_in_main 3
struct THREE_DIMENSIONAL_OUTPUT *array_of_all_structs_in_main[size_of_all_three_dimension_structures_in_main];
*/
#define sys_alignment alignment_var
#define detach_input(input){\shmdt((input));}
#define clean_input(input,shmid_data){\
   shmdt((input));\
   shmctl( shmid_data, IPC_RMID, NULL );\
}
#define detach_proccessed_input(INPUT){\shmdt((INPUT));}
#define clean_processed_input(INPUT){\
	{\
	int key= ((*INPUT).key_of_outputs);\
	shmdt((INPUT));\
	shmctl( key, IPC_RMID, NULL );\
}\
}
void function_clean_input(char *input, int shmid_data){
clean_input(input, shmid_data);
}
void function_clean_processed_input(struct INFO_OUTPUTS_FOR_2d_Proccessing *INPUT){
clean_processed_input(INPUT);
}
#define clean_three_dimentional_processed( THREE_DIMENSIONAL_OUTPUT_pointer,THREE_DIMENSIONAL_OUTPUT_local_variable ){\
for(int i=0;i<THREE_DIMENSIONAL_OUTPUT_local_variable.base_2d_size;i++){\
shmdt((((struct THREE_DIMENSIONAL_OUTPUT*)(((int*)(((THREE_DIMENSIONAL_OUTPUT_local_variable.output_strings)[i])))-2))));\
shmctl(((((THREE_DIMENSIONAL_OUTPUT_local_variable).key_for_all))[i+1]), IPC_RMID,NULL);\
}\
int key_of_struct=((THREE_DIMENSIONAL_OUTPUT_local_variable.key_for_all))[0];\
shmdt((THREE_DIMENSIONAL_OUTPUT_pointer));\
shmctl(key_of_struct, IPC_RMID,NULL);}


void function_clean_three_dimentional_processed(struct THREE_DIMENSIONAL_OUTPUT *THREE_DIMENSIONAL_OUTPUT_pointer){
struct THREE_DIMENSIONAL_OUTPUT THREE_DIMENSIONAL_OUTPUT_local_variable=*THREE_DIMENSIONAL_OUTPUT_pointer;
clean_three_dimentional_processed(THREE_DIMENSIONAL_OUTPUT_pointer, THREE_DIMENSIONAL_OUTPUT_local_variable);
}
#define detach_three_dimentional_processed( THREE_DIMENSIONAL_OUTPUT_pointer, THREE_DIMENSIONAL_OUTPUT_local_variable ){\
{\
for(int i=0;i<THREE_DIMENSIONAL_OUTPUT_local_variable.base_2d_size;i++){\
shmdt((((struct THREE_DIMENSIONAL_OUTPUT*)(((int*)(((*(THREE_DIMENSIONAL_OUTPUT_local_variable.output_strings))[i])))-2))-1));\
}\
shmdt((THREE_DIMENSIONAL_OUTPUT_pointer));\
}\
}

void clean_all(){
struct THREE_DIMENSIONAL_OUTPUT THREE_DIMENSIONAL_OUTPUT_local_variable;
for(int i=0;i<size_of_all_three_dimension_structures_in_main;i++){
THREE_DIMENSIONAL_OUTPUT_local_variable=*(array_of_all_structs_in_main[i]);
clean_three_dimentional_processed(array_of_all_structs_in_main[i],THREE_DIMENSIONAL_OUTPUT_local_variable);
}
}
void function_detach_three_dimentional_processed(struct THREE_DIMENSIONAL_OUTPUT *THREE_DIMENSIONAL_OUTPUT_pointer){
struct THREE_DIMENSIONAL_OUTPUT THREE_DIMENSIONAL_OUTPUT_local_variable=*THREE_DIMENSIONAL_OUTPUT_pointer;
detach_three_dimentional_processed(THREE_DIMENSIONAL_OUTPUT_pointer,THREE_DIMENSIONAL_OUTPUT_local_variable);
}

void detach_all(){
struct THREE_DIMENSIONAL_OUTPUT THREE_DIMENSIONAL_OUTPUT_local_variable;
for(int i=0;i<size_of_all_three_dimension_structures_in_main;i++){
THREE_DIMENSIONAL_OUTPUT_local_variable=*(array_of_all_structs_in_main[i]);
detach_three_dimentional_processed(array_of_all_structs_in_main[i],THREE_DIMENSIONAL_OUTPUT_local_variable);
}
}
void take_input_in_bulk(char **input_array,char **questions_to_ask_for_input,int how_many_inputs, int *key_for_shared_memory, int protection_for_all_memory, int MINIMUM_LIMIT_FOR_BASE_INPUT, int *size_of_each_output_string ){
    
/*
 *the code is a simple optimization of the input function fromm the previous one, the previous code was
 easy to understand but it was a big waste of memory, this one emphasizes on memory usage.
 the lines of code are long considering that its for input only but its meant for optimized input.
 the input function before took input but the memory the input was stored in was then duplicated when
 ever the process was forked which was a big big big big BIG waste of memory.
 so if the user gives u a simple input of 10 lines each line with 10 charactors that means that u have 109 bytes stored
 if u fork  10 times that means ur wasting 1009 bytes of space,Im mean thats a embarrasing amount of wastage, this
 code might make the input function slower depending on the amount of memory ur willing to sacrifice for speed but overall
 , I think its a huge improvement, despite its large size.
 *
 * */
    
       int INITIAL_SIZE_;
   int INITIAL_SIZE;
    int shmid_date;
#ifdef _WIN32

#elif __APPLE__

#elif __linux__
input_bulk_shmget(shmid_date,INITIAL_SIZE,INITIAL_SIZE_);
#else
    



#ifdef _WIN32

#elif __APPLE__

#elif __linux__
input_bulk_shmat(shmid_date,INFO_OUTPUTS);
#else
    
  
for(int counter=0, offset_of_link=0; counter<how_many_inputs;counter++){

printf("%s",questions_to_ask_for_input[counter]); 
   input_array[counter]=((char*)(input_array+how_many_inputs))+offset_of_link;
   char *input=input_array[counter];
   int i=0;
   for(int j=0, c=0, is_limit_reached=0,times_the_limit_reached=1;; i++, is_limit_reached++){
   offset_of_link++;



   if(is_limit_reached==INITIAL_SIZE){
   times_the_limit_reached++;
   u_int8_t back_up[sizeof(char)*INITIAL_SIZE];
   memcpy(back_up, (input), (i+1)*sizeof(char));

    int shmid_date;

#ifdef _WIN32

#elif __APPLE__

#elif __linux__
 input_bulk_shmget_MINUIMUM_OVERFLOW(shmid_date,INITIAL_SIZE,INITIAL_SIZE_ );
#else
   



#ifdef _WIN32

#elif __APPLE__

#elif __linux__
  input_bulk_shmat_MINUIMUM_OVERFLOW(shmid_date,INFO_OUTPUTS);
#else
  


   memset((input), 0, INITIAL_SIZE);
   memcpy( (input), back_up, i+1*sizeof(char));
   is_limit_reached=0;
   }

    (input)[i]=getchar();
   		    
    if((input)[i]=='\n'){
        if(j||c){
        
        }
        else{
        (input)[i]='\0';
	break;
        }
    }


    if((input)[i]=='\''){
         if(j==1){
            j=0;
        
    }
         else{
            if(c==0){
            j=1;
            }
        }
    }
    if((input)[i]=='\"'){
         if(c==1){
            c=0;
        
    }
         else{
            if(j==0){
            c=1;
            }
        }
    }

   }

size_of_each_output_string[counter]=i;
}
   *key_for_shared_memory =shmid_data;
   
    }



int take_input(char **input_global, int *key_for_shared_memory, int protection_for_all_memory, int MINIMUM_LIMIT_FOR_BASE_INPUT ){
    
/*
 *the code is a simple optimization of the input function fromm the previous one, the previous code was
 easy to understand but it was a big waste of memory, this one emphasizes on memory usage.
 the lines of code are long considering that its for input only but its meant for optimized input.
 the input function before took input but the memory the input was stored in was then duplicated when
 ever the process was forked which was a big big big big BIG waste of memory.
 so if the user gives u a simple input of 10 lines each line with 10 charactors that means that u have 109 bytes stored
 if u fork  10 times that means ur wasting 1009 bytes of space,Im mean thats a embarrasing amount of wastage, this
 code might make the input function slower depending on the amount of memory ur willing to sacrifice for speed but overall
 , I think its a huge improvement, despite its large size.
 *
 * */
    char *input;
    int INITIAL_SIZE;
     int INITIAL_SIZE_;
     int shmid_date;
#ifdef _WIN32

#elif __APPLE__

#elif __linux__
    input_normal_shmget(shmid_date,INITIAL_SIZE,INITIAL_SIZE_ );
#else




#ifdef _WIN32

#elif __APPLE__

#elif __linux__
input_normal_shmat(shmid_date,INFO_OUTPUTS);
#else
    

   memset((input), 0, INITIAL_SIZE);

   int i=0;
   for(int j=0, c=0, is_limit_reached=0,times_the_limit_reached=1;; i++, is_limit_reached++){
   if(is_limit_reached==INITIAL_SIZE){
   times_the_limit_reached++;
   char back_up[i+1];
   memcpy(back_up, (input), (i+1)*sizeof(char));
       int shmid_date;

#ifdef _WIN32

#elif __APPLE__

#elif __linux__
    input_normal_shmget_MINUIMUM_OVERFLOW(shmid_date,INITIAL_SIZE,INITIAL_SIZE_ );
#else




#ifdef _WIN32

#elif __APPLE__

#elif __linux__
input_normal_shmat_MINUIMUM_OVERFLOW(shmid_date,INFO_OUTPUTS);
#else
    

   memset((input), 0, INITIAL_SIZE);
   memcpy( (input), back_up, i+1*sizeof(char));
   is_limit_reached=0;
   }

    (input)[i]=getchar();
   		    
    if((input)[i]=='\n'){
        if(j||c){
        
        }
        else{
        (input)[i]='\0';
	break;
        }
    }


    if((input)[i]=='\''){
         if(j==1){
            j=0;
        
    }
         else{
            if(c==0){
            j=1;
            }
        }
    }
    if((input)[i]=='\"'){
         if(c==1){
            c=0;
        
    }
         else{
            if(j==0){
            c=1;
            }
        }
    }

   }

   *key_for_shared_memory =shmid_data;
   *input_global=input;
   return i;
    }


#define take_input_legacy(input,  sizeof_input){\
         memset((void*)input, 0, sizeof_input);\
\
   for(int i=0,j=0, c=0;; i++){\
    if(i ==sizeof_input-1){\
        input[i]= '\0';\
        break;\
    }\
    input[i]=getchar();\
    if(input[i]=='\n'){\
        if(j||c){\
        \
        }\
        else{\
            break;\
        }\
    }\
\
   \
    if(input[i]=='\''){\
         if(j==1){\
            j=0;\
        \
    }\
         else{\
            if(c==0){\
            j=1;\
            }\
        }\
    }\
    if(input[i]=='\"'){\
         if(c==1){\
            c=0;\
        \
    }\
         else{\
            if(j==0){\
            c=1;\
            }\
        }\
    }\
\
   }\
    }
#define MAXIMUM_FUNC 5
struct operations_data{
long int identifier;
char ***string_data;
int key;
struct INFO_OUTPUTS_FOR_2d_Proccessing *base_pointer;//used to detach
};
struct  program_data{
void *local_data;
void *global_data;
struct operation_data *operation_data_array;
void *repeat_data;
void *run_program_data;
} *all_shared_memory;
 struct program_data *all_shared_memory;
int  key_of_all_shared_structures; 
 void init_all(){
   key_of_all_shared_structures= shmget(((((sizeof(struct program_data))+(sizeof(struct operations_data*)*options_selected[1])/alignment_var)+1)*alignment_var);//add the size of any structure after line 47
all_shared_memory=(struct program_data*)shmat(key_of_all_shared_structures, NULL,0);
  (*all_shared_memory).operations_data_array=(struct operations_data*)((&all_shared_memory)+1);
  
}
void init_end_all(){
    
}
void run_program_init(char ***arguments,int *number_of_arguments, int *COMMAND_NUMBER, int *string_NUMBER  ){
    //empty block because no code is needed in this option
}
void operations_init(char ***arguments,int *number_of_arguments, int *COMMAND_NUMBER, int *string_NUMBER  ){
struct INFO_OUTPUTS_FOR_2d_Proccessing *second_input_commands_2d;
        process_input_into_parts(input,second_input_commands_2d, strlen(input),'|', commonly_used_permission_in_main);
   
    
}
void repeat_init(char ***arguments,int *number_of_arguments, int *COMMAND_NUMBER, int *string_NUMBER  ){

}

void local_data_init(char ***arguments,int *number_of_arguments, int *COMMAND_NUMBER, int *string_NUMBER  ){


}

void global_data_init(char ***arguments,int *number_of_arguments, int *COMMAND_NUMBER, int *string_NUMBER  ){


}

    void (*functions_init[MAXIMUM_FUNC])(char ***, int *,int*,int* )={&run_program_init, &operations_init, &repeat_init,&local_data_init, &global_data_init};

void clean_all_function(){
struct THREE_DIMENSIONAL_OUTPUT THREE_DIMENSIONAL_OUTPUT_local_variable;
clean_all(THREE_DIMENSIONAL_OUTPUT_local_variable);
}



void Run_progam(int command_NUMBER,int INSTANCE_NUMBER,char ***strings_to_use, int *number_of_strings,char ***strings_to_use2, int *number_of_strings2){
     if(!strlen(strings_to_use[command_NUMBER][0],"NON-SYNC")){
     //this if statement will let the parent skip and run other options if it wants to
     if(fork()!=0){
     goto parent_skips
     
     }}

     char *argv[number_of_strings[command_NUMBER]+1];
     int amount_of_print_data=0;
    for(int i=0; i<number_of_strings[command_NUMBER]; i++){
        argv[i]= strings_to_use[command_NUMBER][i];
    }
    argv[(number_of_strings[command_NUMBER])]=NULL;
    detach_all();
    execvp(argv[0], argv+1);
	parent_skips:     
}
void Run_progam(int *command_NUMBER,int *INSTANCE_NUMBER,char ***strings_to_use, int *number_of_strings,char ***strings_to_use2, int *number_of_strings2){
} 
void operations(int *command_NUMBER,int *INSTANCE_NUMBER,char ***strings_to_use, int *number_of_strings,char ***strings_to_use2, int *number_of_strings2){
}
void repeat(int *command_NUMBER,int *INSTANCE_NUMBER,char ***strings_to_use, int *number_of_strings,char ***strings_to_use2, int *number_of_strings2){
 }
 void local_data(int *command_number,int *instance_number,char ***strings_to_use, int *number_of_strings,char ***strings_to_use2, int *number_of_strings2){
}

void global_data(int *command_number,int *instance_number,char ***strings_to_use, int *number_of_strings,char ***strings_to_use2, int *number_of_strings2){
}

   void (*functions[MAXIMUM_FUNC])(int, int,char ***,int *, char ***,int *)={&Run_progam, &operations, &repeat, &local_data, &global_data};
void run_program_destroyer(){}
void operations_destroyer(){}
void repeat_destroyer(){}
void local_data_destroyer(){}
void global_data_destroyer(){}
void(*function_destroyer[MAXIMUM_FUNC])()={&Run_progam_destroyer,&operations_destroyer, &repeat_destroyer, &local_data_destroyer, &global_data_destroyer };
#define commonly_used_permission_in_main 0666 
//the macro above is used for all memory for now
#define look_ahead_option_reader_constant 100
int main(){
char *input=NULL; 
int *key_for_shared_memory, size_of_input;
size_of_input=take_input(input_global, key_for_shared_memory, 0666, 100 );
printf("\n data : %s, size: %d\n", input, size_of_input);
/*//testing input functions:
#ifdef _WIN32
        #include <windows.h>
#elif __APPLE__
       #include <xpc/xpc.h>
//#elif __linux__
//	#include <sys/wait.h>
#else
   alignment_var=sysconf(_SC_PAGE_SIZE);


 char **INPUT_DETAILED;
    char ***strings_to_use;
    int *number_of_strings;
    int number_of_COMMANDS;
    char **options;
    int NUMBER_OF_OPTIONS;
char *input;
char *option_initial_string;
 int key_;
int options_=open("file_of_modes", O_RDONLY);
int temp;
lseek(options_,0, SEEK_SET);
temp = dup(STDIN_FILENO);
dup2(options_, (STDIN_FILENO));

take_input(&option_initial_string, &key_, commonly_used_permission_in_main,100);
dup2(temp, STDIN_FILENO);
close(options_);

printf("\n initial options are %s\n", option_initial_string);
struct INFO_OUTPUTS_FOR_2d_Proccessing *first_option_2d; 
process_input_into_parts(option_initial_string, first_option_2d,strlen(option_initial_string), '&',commonly_used_permission_in_main);
printf("\n%p\n", ((*first_option_2d).OUTPUT));
options=((*first_option_2d).OUTPUT);

NUMBER_OF_OPTIONS=(*first_option_2d).NUMBER_OF_OUTPUTS;
clean_input(options, key_);
while (1==1){
	if(fork()==0){
    printf("\nenter ur command:$  ");
   
    take_input(&input, &key_,commonly_used_permission_in_main , 100);
if(!(strcmp(input, "QTE"))){
         
               return 0;
    }
else{
    struct INFO_OUTPUTS_FOR_2d_Proccessing *second_input_commands_2d;
        process_input_into_parts(input,second_input_commands_2d, strlen(input),'|', commonly_used_permission_in_main);
    clean_input(input,key_);
    INPUT_DETAILED=((*second_input_commands_2d).OUTPUT);
    number_of_COMMANDS=(*second_input_commands_2d).NUMBER_OF_OUTPUTS;
    
    //&INPUT_DETAILED, &number_of_COMMANDS, 
    clean_processed_input(second_input_commands_2d);
    struct THREE_DIMENSIONAL_OUTPUT *second_THREE_DIMENSIONAL_OUTPUT;
    array_of_all_structs_in_main[0]=second_THREE_DIMENSIONAL_OUTPUT;

    furthur_process_input(second_THREE_DIMENSIONAL_OUTPUT,INPUT_DETAILED,number_of_COMMANDS, '&', commonly_used_permission_in_main);
    strings_to_use= ((*second_THREE_DIMENSIONAL_OUTPUT).output_strings);
    number_of_strings=((*second_THREE_DIMENSIONAL_OUTPUT).number_of_output_strings);
     
if(!(number_of_COMMANDS>0)){
    }
else{
printf("enter the options:\n");

take_input(&input, &key_,commonly_used_permission_in_main, 100);
char **input_DETAILLLLED;
int Command_Numbers;
char ***strings_to_use1;
int *number_of_strings1;
struct INFO_OUTPUTS_FOR_2d_Proccessing *third_input_commands_2d;

process_input_into_parts(input, third_input_commands_2d,strlen(input),'|', commonly_used_permission_in_main);
clean_input(input,key_);
input_DETAILLLLED=((*third_input_commands_2d).OUTPUT);
Command_Numbers=(*third_input_commands_2d).NUMBER_OF_OUTPUTS;
clean_processed_input(third_input_commands_2d);
    struct THREE_DIMENSIONAL_OUTPUT *third_THREE_DIMENSIONAL_OUTPUT;
 array_of_all_structs_in_main[1]=third_THREE_DIMENSIONAL_OUTPUT;   
    furthur_process_input(third_THREE_DIMENSIONAL_OUTPUT,INPUT_DETAILED,number_of_COMMANDS, '&', commonly_used_permission_in_main);
    strings_to_use1= (((*third_THREE_DIMENSIONAL_OUTPUT).output_strings));
    number_of_strings1=((*third_THREE_DIMENSIONAL_OUTPUT).number_of_output_strings);


char ***strings_to_use2;
int *number_of_strings2;
int Command_Numbers2;
fprintf(stderr, "enter the arguments for the options YOU chose:\n");
take_input(&input, &key_,commonly_used_permission_in_main, 100);
struct INFO_OUTPUTS_FOR_2d_Proccessing *forth_input_commands_2d;

process_input_into_parts(input, forth_input_commands_2d,strlen(input),'|', commonly_used_permission_in_main);
clean_input(input,key_);
input_DETAILLLLED=((*forth_input_commands_2d).OUTPUT);
Command_Numbers2=(*forth_input_commands_2d).NUMBER_OF_OUTPUTS;
clean_processed_input(forth_input_commands_2d);

    struct THREE_DIMENSIONAL_OUTPUT *forth_THREE_DIMENSIONAL_OUTPUT;
    array_of_all_structs_in_main[2]=forth_THREE_DIMENSIONAL_OUTPUT;
    furthur_process_input(forth_THREE_DIMENSIONAL_OUTPUT,INPUT_DETAILED,number_of_COMMANDS, '&', commonly_used_permission_in_main);
    strings_to_use2= (((*forth_THREE_DIMENSIONAL_OUTPUT).output_strings));
    number_of_strings2=((*forth_THREE_DIMENSIONAL_OUTPUT).number_of_output_strings);



options_selected=malloc(MAXIMUM_FUNC*sizeof(uint8_t));
memset(options_selected, 1, MAXIMUM_FUNC*sizeof(uint8_t));
for(int i =0; i<number_of_COMMANDS; i++){

for(int j=0; j<NUMBER_OF_OPTIONS; j++){
if(j==MAXIMUM_FUNC){
    break;
}
for(int i1=0; i1<number_of_strings1[i]; i1++){
if(!(strcmp(strings_to_use1[i][i1], options[j]))){
	    options_selected[j]++;	    
            functions_init[j](strings_to_use2, number_of_strings2, i,i1);
}
}
}
free(options_selected);
init_all();
}
for(int i =0; i<number_of_COMMANDS; i++){

if(fork()==0){


for(int i2 =0;i2<MAXIMUM_FUNC; i2++){
if(!options_selected[i2]){
function_destroyer[i2]();
}}
free(options_selected);

for(int i1=0; i1<number_of_strings1[i]; i1++){
if(j==MAXIMUM_FUNC){
    break;
}
for(int j=0; j<NUMBER_OF_OPTIONS; j++){
if(!(strcmp(strings_to_use1[i][i1], options[j]))){
	    	    
            functions[j](i,i1,strings_to_use, number_of_strings,strings_to_use2, number_of_strings2);
}
}
}
{
struct THREE_DIMENSIONAL_OUTPUT THREE_DIMENSIONAL_OUTPUT_local_variable;
detach_all(THREE_DIMENSIONAL_OUTPUT_local_variable);

}
shmdt(all_shared_memory);
return 0;}}init_end_all();for
(int i=0; i<number_of_COMMANDS; i++){wait(NULL);}
return 0;}}
 
  
    }
wait(NULL);
clean_all_label:{
struct THREE_DIMENSIONAL_OUTPUT THREE_DIMENSIONAL_OUTPUT_local_variable;
clean_all(THREE_DIMENSIONAL_OUTPUT_local_variable);
		}
		}

return 0;*/
}
