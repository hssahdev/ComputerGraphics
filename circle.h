void circle(int x0,int y0, int r){
    
    float x,y;
    x=0;
    y=r;
    putpixel(x,y);
    while(x<=y){
        float x_mid = x+1;
        float y_mid = y-0.5;

        float d = x_mid*x_mid + y_mid*y_mid - r*r;

        if(d<=0){
            x++;
            glBegin(GL_POINTS);
            glVertex2i(x+x0,y+y0);    
            glVertex2i(y+x0,x+y0);
            glVertex2i(x+x0,-y+y0);
            glVertex2i(y+x0,-x+y0);
            glVertex2i(-x+x0,y+y0);
            glVertex2i(-y+x0,x+y0);
            glVertex2i(-x+x0,-y+y0);
            glVertex2i(-y+x0,-x+y0);
            glEnd();
        }
        else{
            x++;
            y--;
            glBegin(GL_POINTS);
            glVertex2i(x+x0,y+y0);    
            glVertex2i(y+x0,x+y0);
            glVertex2i(x+x0,-y+y0);
            glVertex2i(y+x0,-x+y0);
            glVertex2i(-x+x0,y+y0);
            glVertex2i(-y+x0,x+y0);
            glVertex2i(-x+x0,-y+y0);
            glVertex2i(-y+x0,-x+y0);
            glEnd();
        }
    }
}

