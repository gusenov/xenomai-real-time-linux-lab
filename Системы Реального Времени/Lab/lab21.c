#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <linux/kd.h>


int main()
{
int lamp1 = 0;
int lamp2 = 0;
int lamp3 = 0;
char x = ' ';
printf("Starting... Press any key to continue...\n");
do
{
x = getch();
printf("The key you entered is: %c \n", x);
if (x=='z')
{
printf("ZZZ \n");
}

if ((x=='a') && (lamp1==0))
{
lamp1 = 1;
}
else if ((x=='a') && (lamp1==1))
{
lamp1 = 0;
}
else if ((x=='s') && (lamp2==0))
{
lamp2 = 1;
}
else if ((x=='s') && (lamp2==1))
{
lamp2 = 0;
}
else if ((x=='d') && (lamp3==0))
{
lamp3 = 1;
}
else if ((x=='d') && (lamp3==1))
{
lamp3 = 0;
}
if (lamp1==0) printf("Lamp1 Off ");
if (lamp1==1) printf("Lamp1 On ");
if (lamp2==0) printf("Lamp2 Off ");
if (lamp2==1) printf("Lamp2 On ");
if (lamp3==0) printf("Lamp3 Off ");
if (lamp3==1) printf("Lamp3 On ");
printf("\n");
printf("Uksusov_Aybyatov_Karpuhin_Anfinogentova_Grishin");
}



while (x !='q');
return 0;

}

int getch(void)
{
int ch;
struct termios oldt;
struct termios newt;
tcgetattr(STDIN_FILENO, &oldt); /*store old settings */
newt = oldt; /* copy old settings to new settings */
newt.c_lflag &= ~(ICANON | ECHO); /* make one change to old settings in new settings */
tcsetattr(STDIN_FILENO, TCSANOW, &newt); /*apply the new settings immediatly */
ch = getchar(); /* standard getchar call */
tcsetattr(STDIN_FILENO, TCSANOW, &oldt); /*reapply the old settings */
return ch; /*return received char */
}

