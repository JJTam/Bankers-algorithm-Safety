/**
 
  Name: Tan YongJie
  ITSC Email address: ytanaq@connect.ust.hk

  TODO: Explanation of Banker's algorithm (Safety). 
  You should use point form to explain how you implement this algorithm. For example:

    Step 1: define two local variables (int safe = 0 & int step = 0) to store the status of the process
    Step 2: print out some initial stage of message & work & finish
    Step 3: enter the outer for loop, int a starts from 0 to the num of process - 1
    Step 4: enter the inner for loop, int i starts from 0 to the num of process - 1
        Step 4.1: check whether finish[i] is equal to 0 (false) or not
        Step 4.2: if finish[i] is equal to 0, then
            Step 4.2.1: define a local variable to store the status of pass (pass = 1)
            Step 4.2.2: enter the for loop, int j starts from 0 to the num of resource - 1
                Step 4.2.2.1: check whether need_i > work,
                Step 4.2.2.2: if true, then pass will be 0, and break this for loop then go back to Step 4
            Step 4.2.3: if pass is 1, which means all need_i <= work, then
                Step 4.2.3.1: set finish[i] to true
                Step 4.2.3.2: set the sequence
                Step 4.2.3.3: update the int step
                Step 4.2.3.4: enter the for loop, int n starts from 0 to the num of resource
                    Step 4.2.3.4.1: update the work: work = work + alloc
                Step 4.2.3.5: print out the updated step & work & finish
                Step 4.2.3.6: break this for loop, and go back to Step 3, which means reset the i, so that it can always choose the smallest index that satisfies the conditions
        Step 4.3: if finish[i] is equal to 1, then go back to step 4
    Step 5: enter the for loop, int i starts from 0 to the num of process - 1
        Step 5.1: int safe is initialized to 1
        Step 5.2: check whether all processes are finished
            Step 5.2.1: if there is unfinished process, then int safe will be 0 and break this for loop
    Step 6: print out the result message
    Step 7: check whether the int safe is 1 or not
        Step 7.1: if int safe is 1, which means that after all checking and calculations, the system is safe
            Step 7.1.1: print out the safety message and print out all the sequences
        Step 7.2: if int safe is not 1, which means that the system is not safe
            Step 7.2.1: print out the unsafe message
            Step 7.2.2: check whether all processes are failed or not
                Step 7.2.2.1: if all processes are failed, then print out the empty seq
                Step 7.2.2.2: if there have some finished process, then use the for loop to print them out
 */

// This line should be placed before including <stdio.h>
#define _GNU_SOURCE 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the MAX_RESOURCE and MAX_PROCESS
#define MAX_RESOURCE 10
#define MAX_PROCESS 10


// Check whether the line is a blank line (for input parsing)
int is_blank(char *line) {
    char *ch = line;
    while (*ch != '\0') {
        if (!isspace(*ch))
            return 0;
        ch++;
    }
    return 1;
}


// Check whether the input line should be skipped
int is_skip(char *line) {
    if (is_blank(line))
        return 1;
    char *ch = line ;
    while (*ch != '\0') {
        if (!isspace(*ch) && *ch == '#')
            return 1;
        ch++;
    }
    return 0;
}


// print the matrix in banker's algorithm
void print_mat(char *name, int mat[MAX_PROCESS][MAX_RESOURCE], int num_process, int num_resource) {
    int i, j;
    printf("%s = [\n", name);
    for (j = 0; j < num_process; j++) {
        for (i = 0; i < num_resource; i++) {
            printf("%d", mat[j][i]);
            if (i < num_resource - 1)
                printf(",");
        }
        printf("\n");
    }
    printf("]\n");
}

// print a vector in banker's algorithm
void print_vec(char *name, int vec[MAX_RESOURCE], int n) {
    int i;
    printf("%s = [", name);
    for (i = 0; i < n; i++) {
        printf("%d", vec[i]);
        if (i < n - 1)
            printf(",");
    }
    printf("]\n");
}




int main() {

    FILE *fp = stdin;
    char *line = NULL;
    ssize_t  nread;
    size_t len = 0;

    char algorithm[100];    
    int num_resource; // m
    int num_process; // n
    int alloc[MAX_PROCESS][MAX_RESOURCE]; // n x m
    int max[MAX_PROCESS][MAX_RESOURCE]; // n x m
    int need[MAX_PROCESS][MAX_RESOURCE]; // n x m
    int work[MAX_RESOURCE]; // m vector
    int finish[MAX_PROCESS]; // n vector
    int seq[MAX_PROCESS]; // n vector

    int line_count = 0;
    int i = 0;
    int j = 0;


     // ==== Start: Input parsing ====

    while ((nread = getline(&line, &len, fp)) != -1) {
        if ( is_skip(line) == 0)  {

            line_count++;
            line = strtok(line,"\n");

            if (line_count == 1) {
                strcpy(algorithm, line);
            }
            else if (line_count == 2) {
                sscanf(line, "%d", &num_resource);
            }
            else if (line_count == 3) {
                sscanf(line, "%d", &num_process);
            }
            else if (line_count == 4) {
                line = strtok(line, " ");
                i = 0;
                while (line != NULL) {
                    sscanf(line, "%d", &work[i]);
                    i++;
                    line = strtok(NULL," ");
                }
            }
            else if (line_count >= 5 && line_count <= (5 + num_process - 1)) {
                j = line_count - 5;
                line = strtok(line, " ");
                i = 0;
                while (line != NULL) {
                    sscanf(line, "%d", &alloc[j][i]);
                    i++;
                    line = strtok(NULL," ");
                }
            }
            else if (line_count >= 5 + num_process && line_count <= 5 + 2 * num_process - 1) {
                j = line_count - 5 - num_process;
                line = strtok(line, " ");
                i = 0;
                while (line != NULL) {
                    sscanf(line, "%d", &max[j][i]);
                    i++;
                    line = strtok(NULL," ");
                }
            }
        }
    }

    printf("=== Banker's algorithm input values ===\n");
    printf("algorithm = %s\n", algorithm);
    printf("m = %d\n", num_resource);
    printf("n = %d\n", num_process);
    print_vec("work", work, num_resource);
    print_mat("alloc", alloc, num_process, num_resource);
    print_mat("max", max, num_process, num_resource);

    for (j = 0; j < num_process; j++)
        for (i = 0; i < num_resource; i++)
            need[j][i] = max[j][i] - alloc[j][i];

    print_mat("need", need, num_process, num_resource);

    for (i = 0; i < num_process; i++) {
        finish[i] = 0;
        seq[i] = -1;
    }

    print_vec("finish", finish, num_process);

    // ==== Done: Input parsing ====

    // TODO: Implement the banker's algorithm here
    int safe = 0;
    int step = 0;
    printf("=== Banker's algorithm execution ===\n");
    printf("=== Step %d ===\n", step);
    print_vec("work", work, num_resource);
    print_vec("finish", finish, num_process);
    for (int a = 0; a < num_process; a++) {
        for (i = 0; i < num_process; i++) {
            if (finish[i] == 0) {  // finish[i] is equal to false
                int pass = 1;
                for (j = 0; j < num_resource; ++j) {
                    if (need[i][j] > work[j]) {  // need_i > work
                        pass = 0;
                        break;
                    }
                }

                if (pass == 1) {  // all need_i <= work
                    finish[i] = 1;  // set finish[i] to true
                    seq[step] = i;  // set the sequence
                    step++;  // update step
                    for (int n = 0; n < num_resource; n++) {
                        work[n] += alloc[i][n];  // update the work: work = work + alloc
                    }
                    printf("=== Step %d ===\n", step);
                    print_vec("work", work, num_resource);
                    print_vec("finish", finish, num_process);
                    break;  // reset the i, so that always choose the smallest index that satisfies the conditions
                }
            }
        }
    }

    for (i = 0; i < num_process; i++) {  // check whether all processes are finished
        safe = 1;
        if (finish[i] != 1) {
            safe = 0;
            break;
        }
    }

    printf("=== Banker's algorithm result ===\n");
    if (safe == 1) {  // after all checking and calculations, the system is safe
        printf("The system is safe\n");
        print_vec("seq", seq, num_process);  // print all the sequences
    }
    else {
        printf("The system is not safe\n");
        if (step == 0) {  // all processes are failed
            printf("seq = []\n");
        }
        else {  // some processes are finished
            printf("seq = [");
            for (i = 0; i < num_process; i++) {
                if (seq[i] != -1) {
                    printf("%d", seq[i]);
                    if (i < step - 1)
                        printf(",");
                }
            }
            printf("]\n");
        }
    }

    return 0;
}
