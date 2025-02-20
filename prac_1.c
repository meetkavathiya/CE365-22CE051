#include <stdio.h>
#include <string.h>

int main(void) {
     
     char input[200];

     gets(input);

    int n=strlen(input);

   
    int f,is_b=0;
    int b_count=0;
    

    for(int i=0;i<n;i++)
    {
     if(input[i]=='a' && is_b==0 )
     {
       f=1;
     }
     else if(input[i]=='b' && b_count<2  )
     {
        is_b=1;
        f=1;
        b_count++;
     }
     else
     {
        f=0;
        break;
     }

    }

    if(f==1 && b_count==2)
    {
        printf("valid string");
    }
    else
    {
        printf("invalid string");
    }

    return 0;
}
// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     char input[200];

//     // Read input safely
//     printf("Enter a string: ");
//     if (fgets(input, sizeof(input), stdin) != NULL) {
//         // Remove the trailing newline character, if present
//         input[strcspn(input, "\n")] = '\0';
//     }

//     int n = strlen(input);
//     int is_b = 0;
//     int b_count = 0;
//     int f = 1; // Assume valid initially

//     for (int i = 0; i < n; i++) {
//         if (input[i] == 'a' && is_b == 0) {
//             f = 1; // Still valid
//         } else if (input[i] == 'b' && b_count < 2) {
//             is_b = 1; // Start counting 'b's
//             b_count++;
//         } else {
//             f = 0; // Invalid character or too many 'b's
//             break;
//         }
//     }

//     if (f == 1 && b_count == 2) {
//         printf("valid string\n");
//     } else {
//         printf("invalid string\n");
//     }

//     return 0;
// }


