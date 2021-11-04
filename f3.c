int tempc = 25, tempf;
extern int c2f(int c);
extern void show(void);
void main()
{
    tempf = c2f(tempc);
    printf("Name : Jeel Dhamsaniya");
    printf("Roll no : IT026");
    printf("Temperature in farenheit is : %d",tempf);
    show();
}