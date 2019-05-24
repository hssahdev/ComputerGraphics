void drawellipse(int a, int b, int x0, int y0)
{
   int p=b*b-a*a*b+a*a/4;
   int x=0;
   int y=b;
   while(b*b*x <= a*a*y)
   {
	if(p < 0)
	{
		x++;
		p = p+2*b*b*x+b*b;
	}
	else
	{
		x++;y--;
		p = p+2*b*b*x-2*a*a*y-b*b;
	}
	putpixel(x0+x,y0+y);
	putpixel(x0+x,y0-y);
	putpixel(x0-x,y0+y);
	putpixel(x0-x,y0-y);
   }

  //Region 2
   p=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
   while(y > 0)
   {
	if(p <= 0)
	{
		x++;y--;
		p = p+2*b*b*x-2*a*a*y+a*a;
	}
	else
	{
		y--;
		p = p-2*a*a*y+a*a;
	}
	putpixel(x0+x,y0+y);
	putpixel(x0+x,y0-y);
	putpixel(x0-x,y0+y);
	putpixel(x0-x,y0-y);
   }
}