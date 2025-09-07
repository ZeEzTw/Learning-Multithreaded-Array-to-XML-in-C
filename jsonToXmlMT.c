#include <stdio.h>
#include <pthread.h>

typedef struct
{
    int *array;
    int size;
    FILE *fp;
} ThreadData;

void *printArrayToXML(void *arg)
{
    ThreadData *data = (ThreadData *)arg;
    printf("Thread %d: Converting JSON to XML...\n", data->array[0]);
    // Simulate conversion work
    fprintf(data->fp, "<data>\n");
    for (int i = 0; i < 5000000; i++)
    { // Simulate time-consuming task
        for (int i = 0; i < 5; i++)
        {
            fprintf(data->fp, "    <nr> %d </nr>\n", data->array[i]);
        }
    }
    fprintf(data->fp, "</data>\n");
    printf("Thread %d: Conversion complete.\n", data->array[0]);
    return NULL;
}
int main()
{
    pthread_t threads1;
    pthread_t threads2;
    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {6, 7, 8, 9, 10};
    FILE *fp = fopen("output1.xml", "w");
    FILE *fp2 = fopen("output2.xml", "w");

    ThreadData data1 = {array1, 5, fp};
    ThreadData data2 = {array2, 5, fp2};

    pthread_create(&threads1, NULL, printArrayToXML, (void *)&data1);
    pthread_create(&threads2, NULL, printArrayToXML, (void *)&data2);

    pthread_join(threads1, NULL);
    pthread_join(threads2, NULL);

    //printArrayToXML((void *)&data1);
    //printArrayToXML((void *)&data2);
    
    fclose(fp);
    fclose(fp2);
    return 0;
}