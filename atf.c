#include "atf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>      
//#include <unistd.h>  


void print_configuration(int* values, int num_values) { 
  for (int i = 0; i < num_values; ++i) {
    printf("%5d", values[i]);
  }
  printf("\n"); 
}

tp_t create_tp(char* name, int min, int max, constraint_t constraint) {
  tp_t t;
  t.name = name;
  t.min = min;
  t.max = max;
  t.constraint = constraint;
  return t;
}

// Part of task 1: This function initializes the array with the input-parameters. 
// This has to be done for every possible combination of values before they get tested.
void initialize_input_parameters(int inputParam[], int counters[], int num_parameters){
  for(int i = 0; i < num_parameters; ++i){
    inputParam[i] = counters[i]; // Initialize the inputParam-Array with the counter-values
  }
}

// This method is part of task 1 and is responsible for validate the combination of values in the search space and to print them if they go as possible
void test_and_print(bool answer, tp_t* parameters, int num_parameters,
                    search_space_t* search_space, int inputParam[], int values[]){
  answer = true; // This variable helps to keep the overview; it functions as a counter. Until it stays on true the combination works for the given constraint.
  int k = 0; // k is a pointer
  while(answer == true && k < num_parameters){
    if(parameters[k].constraint != NULL){
      answer = parameters[k].constraint(inputParam[0],inputParam[1],inputParam[2],inputParam[3],inputParam[4],inputParam[5],inputParam[6],inputParam[7],inputParam[8],inputParam[9]);
    }
    ++k;
  }
  if(answer == true) {
    // print_configuration(values, num_parameters);  // PART OF TASK 1: If there exists a valid combination it gets printed
    search_space_element** elem = &(search_space->elements);
    if(*elem != NULL){ // EVTL RAUSNEHMEN?? NUR WENN FINSL TEST LÄUFT
      while((*elem)->nextElem != NULL) elem = (search_space_element**) &((*elem)->nextElem);
    elem = (search_space_element**) &((*elem)->nextElem);
    }

    *elem = (search_space_element*) malloc(sizeof(search_space_element));
    (*elem)->nextElem = NULL; // Initialize the next-pointer with the default NULL

    (*elem)->configuration.size = num_parameters;
    (*elem)->configuration.values = (int*) malloc(10 * sizeof(int));
    (*elem)->configuration.parameters = (tp_t**) malloc(num_parameters * sizeof(tp_t*));
          
    for(int i = 0; i < num_parameters; ++i){ // Fills the parameters and the values of the configuration
        (*elem)->configuration.parameters[i] = &parameters[i];
        (*elem)->configuration.values[i] = values[i];
    }
    ++search_space->size; // Part of task 2: Increases the number of valid combination in the searchspace by one 
    /*for(int i=0; i<num_parameters; ++i){
        printf("value: %d", (*elem)->configuration.values[i]);
    }*/
  }
}

void generate_search_space(tp_t* parameters, int num_parameters,
                           search_space_t* search_space) {
  
  search_space->size = 0;
  search_space->elements = NULL;
  bool answer = false; // This parameter will we used to check, whether a combination of parameters is valid
  int values[num_parameters]; // This array will contain all current values which might get printed
  int inputParam[10] = {0,0,0,0,0,0,0,0,0,0}; // This array will contain the input values
  for(int i = 0; i < num_parameters; ++i){ // This for-loop will set the start values vor the value-array with the minimum parameter value
    values[i] = parameters[i].min;
  }

  initialize_input_parameters(inputParam, values, num_parameters); // Now the input-parameter array gets filled with the current values to use them for the validation check later on

  for(int a = parameters[0].min; a <= parameters[0].max; ++a){

      values[0] = a; 
      initialize_input_parameters(inputParam, values, num_parameters);
      
      if(num_parameters > 1){
        for(int b = parameters[1].min; b <= parameters[1].max; ++b){

          values[1] = b;
          initialize_input_parameters(inputParam, values, num_parameters);
          if(num_parameters > 2){
            for(int c = parameters[2].min; c <= parameters[2].max; ++c){

              values[2] = c; 
              initialize_input_parameters(inputParam, values, num_parameters);
              if(num_parameters > 3){
                for(int d = parameters[3].min; d <= parameters[3].max; ++d){

                  values[3] = d; 
                  initialize_input_parameters(inputParam, values, num_parameters);
                  if(num_parameters > 4){
                    for(int e = parameters[4].min; e <= parameters[4].max; ++e){
                      values[4] = e; 
                      initialize_input_parameters(inputParam, values, num_parameters);
                      
                      if(num_parameters > 5){
                        for(int f = parameters[5].min; f <= parameters[5].max; ++f){
                          values[5] = f; 
                          initialize_input_parameters(inputParam, values, num_parameters);  
                          
                          if(num_parameters > 6){
                            for(int g = parameters[6].min; g <= parameters[6].max; ++g){
                              values[6] = g; 
                              initialize_input_parameters(inputParam, values, num_parameters);  
                              
                              if(num_parameters > 7){
                                for(int h = parameters[7].min; h <= parameters[7].max; ++h){
                                  values[7] = h; 
                                  initialize_input_parameters(inputParam, values, num_parameters);  
                                  
                                  if(num_parameters > 8){
                                    for(int i = parameters[8].min; i <= parameters[8].max; ++i){
                                      values[8] = i; 
                                      initialize_input_parameters(inputParam, values, num_parameters);  
                                      
                                      if(num_parameters > 9){
                                        for(int j = parameters[9].min; j <= parameters[9].max; ++j){
                                          values[9] = j; 
                                          initialize_input_parameters(inputParam, values, num_parameters);
                                          
                                          if(num_parameters == 10){
                                            test_and_print(answer, parameters, num_parameters, search_space, inputParam, values); 
                                          }
                                        }
                                      }

                                      if(num_parameters == 9){
                                        test_and_print(answer, parameters, num_parameters, search_space, inputParam, values);
                                      }
                                    }
                                  }

                                  if(num_parameters == 8){
                                    test_and_print(answer, parameters, num_parameters, search_space, inputParam, values);
                                  }
                                }
                              }

                              if(num_parameters == 7){
                                test_and_print(answer, parameters, num_parameters, search_space, inputParam, values); 
                              }
                            } 
                          }

                          if(num_parameters == 6){
                            test_and_print(answer, parameters, num_parameters, search_space, inputParam, values);
                          } 
                        }
                      }

                      if(num_parameters == 5){
                        test_and_print(answer, parameters, num_parameters, search_space, inputParam, values);
                      }
                    }
                  }

                  if(num_parameters == 4){
                    test_and_print(answer, parameters, num_parameters, search_space, inputParam, values);
                  }
                }
              }

              if(num_parameters == 3){
                test_and_print(answer, parameters, num_parameters, search_space, inputParam, values); 
              }
            }
          }

          if(num_parameters == 2){
            test_and_print(answer, parameters, num_parameters, search_space, inputParam, values);
          }
        }
      } 
  
      if(num_parameters == 1){
        test_and_print(answer, parameters, num_parameters, search_space, inputParam, values);
      }
  } 
}

configuration_t get_config(search_space_t* search_space, int index) {
  search_space_element* element = search_space->elements;
  for(int i=0; i<index; ++i){ // Iterates through the linked list of elements until the wanted index ist reached
    element = (search_space_element*) element->nextElem;
  }
  return element->configuration;
}

void free_search_space(search_space_t* search_space) {
  search_space_element* element = search_space->elements; // The element names the pointer to the head of the linked list of elements
  for(int i=0; i < search_space->size; ++i){ // Iterates through the linked list
    search_space_element* nextElement = (search_space_element*) element->nextElem; // Pointer to the next element in the linked list
    //free(element->configuration.parameters); // Frees the spaces
    //free(element->configuration.values);
    free(element);
    element = nextElement; // element is now the next element until there is no next element / the iteration stopps
  }
}

int getRandomConf(int lower, int upper){ // Returns a random number in the interval [lower:upper]:
  srand((double)clock());
  int num = (rand() % (upper - lower - 1)) + lower;
  return num;
}

void explore_search_space(search_space_t* search_space, cost_function_t cost_function,
                          SEARCH_STRATEGY search_strategy, ABORT_TYPE abort_type, int abort_value,
                          configuration_t* best_config, int* cost) {

  configuration_t min_conf = get_config(search_space, 0); // Standard best_configuration is the first one in the search_space
  int min_cos = cost_function(min_conf.values[0],min_conf.values[1],min_conf.values[2],min_conf.values[3],min_conf.values[4],
                                min_conf.values[5],min_conf.values[6],min_conf.values[7],min_conf.values[8],min_conf.values[9]);
  configuration_t* config = (configuration_t*) malloc(sizeof(configuration_t)); // Gets the checked configuration
  int* this_cost = (int*) malloc(sizeof(int)); // Gets the costs of the current checked configuration
    
  *best_config = min_conf;
  *cost = min_cos;

  if(search_strategy == EXHAUSTIVE){
    if(abort_type == EVALUATIONS){
      if(abort_value > search_space->size){
        for(int i=0; i<abort_value; ++i){
          *config = get_config(search_space, i);
          *this_cost = cost_function((*config).values[0],(*config).values[1],(*config).values[2],(*config).values[3],(*config).values[4],
                                        (*config).values[5],(*config).values[6],(*config).values[7],(*config).values[8],(*config).values[9]);
          if((*this_cost) < (*cost)){
            *cost = *this_cost;
            *best_config = *config;
          }
        }
      } else {
        for(int i=0; i<search_space->size; ++i){
          *config = get_config(search_space, i);
          *this_cost = cost_function((*config).values[0],(*config).values[1],(*config).values[2],(*config).values[3],(*config).values[4],
                                        (*config).values[5],(*config).values[6],(*config).values[7],(*config).values[8],(*config).values[9]);

          if((*this_cost) < (*cost)){
            *cost = *this_cost;
            *best_config = *config;
          }
        }
      }
    } else if(abort_type == SECONDS){ // WORKS
      time_t begin = time(NULL);
      time_t end = time(NULL);      

      int i = 0;
      while((int)end-(int)begin < abort_value && i < search_space->size){
        *config = get_config(search_space, i);
        *this_cost = cost_function((*config).values[0],(*config).values[1],(*config).values[2],(*config).values[3],(*config).values[4],
                                  (*config).values[5],(*config).values[6],(*config).values[7],(*config).values[8],(*config).values[9]);
        if((*this_cost) < (*cost)){
          *best_config = *config;
          *cost = *this_cost;
        }
        ++i;
        end = time(NULL);
      }
    } else if(abort_type == MINUTES){
      time_t begin = time(NULL);
      time_t end = time(NULL);      

      int i = 0;
      while(((int)end-(int)begin) / 60 < abort_value && i < search_space->size){
        *config = get_config(search_space, i);
        *this_cost = cost_function((*config).values[0],(*config).values[1],(*config).values[2],(*config).values[3],(*config).values[4],
                                  (*config).values[5],(*config).values[6],(*config).values[7],(*config).values[8],(*config).values[9]);
        if((*this_cost) < (*cost)){
          *best_config = *config;
          *cost = *this_cost;
        }
        ++i;
        end = time(NULL);
      }
    } else if(abort_type == HOURS){
      time_t begin = time(NULL);
      time_t end = time(NULL);      

      int i = 0;
      while(((int)end-(int)begin) / 60 / 60 < abort_value && i < search_space->size){
        *config = get_config(search_space, i);
        *this_cost = cost_function((*config).values[0],(*config).values[1],(*config).values[2],(*config).values[3],(*config).values[4],
                                  (*config).values[5],(*config).values[6],(*config).values[7],(*config).values[8],(*config).values[9]);
        if((*this_cost) < (*cost)){
          *best_config = *config;
          *cost = *this_cost;
        }
        ++i;
        end = time(NULL);
      }
    } else {
      printf("This ABORT_TYPE does not exist!");
    }
  } else if(search_strategy == RANDOM){ // WORKS
    if(abort_type == EVALUATIONS){
      if(abort_value > 1){
        int i = 0;
        while(i < abort_value){
          *config = get_config(search_space, getRandomConf(0,search_space->size));
          printf("%d, %d, %d\n", (*config).values[0],(*config).values[1],(*config).values[2]);
          *this_cost = cost_function((*config).values[0],(*config).values[1],(*config).values[2],(*config).values[3],(*config).values[4],
                                        (*config).values[5],(*config).values[6],(*config).values[7],(*config).values[8],(*config).values[9]);
          if((*this_cost) < (*cost)){
            *cost = *this_cost;
            *best_config = *config;
          }
          ++i;
        }
      } else {
        *config = get_config(search_space, getRandomConf(0,search_space->size));
        printf("%d, %d, %d\n", (*config).values[0],(*config).values[1],(*config).values[2]);
        *this_cost = cost_function((*config).values[0],(*config).values[1],(*config).values[2],(*config).values[3],(*config).values[4],
                                  (*config).values[5],(*config).values[6],(*config).values[7],(*config).values[8],(*config).values[9]);
        *cost = *this_cost;
        *best_config = *config;
      }
      
    } else if(abort_type == SECONDS){
      clock_t begin = clock();
      clock_t end = clock();

      while(((double)(end-begin) / CLOCKS_PER_SEC) < (double)abort_value){
        *config = get_config(search_space, getRandomConf(0,search_space->size));
        *this_cost = cost_function((*config).values[0],(*config).values[1],(*config).values[2],(*config).values[3],(*config).values[4],
                                  (*config).values[5],(*config).values[6],(*config).values[7],(*config).values[8],(*config).values[9]);
        printf("%d, %d, %d, cost: %d\n", (*config).values[0],(*config).values[1],(*config).values[2], *this_cost);
        if((*this_cost) < (*cost)){
          *best_config = *config;
          *cost = *this_cost;
        }
        end = clock();
      }
    } else if(abort_type == MINUTES){
      clock_t begin = clock();
      clock_t end = clock();

      while(((double)(end-begin) / CLOCKS_PER_SEC) / 60.0 < (double)abort_value){
        *config = get_config(search_space, getRandomConf(0,search_space->size));
        *this_cost = cost_function((*config).values[0],(*config).values[1],(*config).values[2],(*config).values[3],(*config).values[4],
                                  (*config).values[5],(*config).values[6],(*config).values[7],(*config).values[8],(*config).values[9]);
        if((*this_cost) < (*cost)){
          *best_config = *config;
          *cost = *this_cost;
        }
        end = clock();
      }
    } else if(abort_type == HOURS){
      clock_t begin = clock();
      clock_t end = clock();

      while(((double)(end-begin) / CLOCKS_PER_SEC) / 60.0 / 60.0 < abort_value){
        *config = get_config(search_space, getRandomConf(0,search_space->size));
        *this_cost = cost_function((*config).values[0],(*config).values[1],(*config).values[2],(*config).values[3],(*config).values[4],
                                  (*config).values[5],(*config).values[6],(*config).values[7],(*config).values[8],(*config).values[9]);
        if((*this_cost) < (*cost)){
          *best_config = *config;
          *cost = *this_cost;
        }
        end = time(NULL);
      }
    } else {
      printf("This ABORT_TYPE does not exist!");
    }
  }   
}
