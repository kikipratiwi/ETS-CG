POINT point_rotate_cw(int xCenter, int yCenter, int x, int y, float degree)
{
     float xR , yR; 
     POINT p_rotate;
     
     int xTrans, yTrans;
     double val = PI / 180.0;

     //tranlasi awal
     xTrans = x - xCenter;
     yTrans = y - yCenter;

     //cari point rotate
     xR = xTrans * cos(val * degree) + yTrans * sin(val * degree);
     yR = yTrans * sin(val * degree) + xTrans * cos(val * degree);

     //tranlasi akhir  
     xR = xR + (xCenter);
     yR = yR + (yCenter);
     
     p_rotate.x = ROUND(xR);
     p_rotate.y = ROUND(yR);
    //  p_rotate.x = xR+0.5;
    //  p_rotate.y = yR+0.5;
     
     return p_rotate; 
}

POINT point_rotate_ccw(int xCenter, int yCenter, int x, int y, float degree)
{
     float xR , yR; 
     POINT p_rotate;
     
     int xTrans, yTrans;
     double val = PI / 180.0;

     //tranlasi awal
     xTrans = x - xCenter;
     yTrans = y - yCenter;

     //cari point rotate
     xR = xTrans * cos(val * degree) + yTrans * sin(val * degree);
     yR = yTrans * -(sin(val * degree)) + xTrans * cos(val * degree);

     //tranlasi akhir  
     xR = xR + (xCenter);
     yR = yR + (yCenter);
     
     p_rotate.x = ROUND(xR);
     p_rotate.y = ROUND(yR);
    //  p_rotate.x = xR+0.5;
    //  p_rotate.y = yR+0.5;
     
     return p_rotate; 
}

