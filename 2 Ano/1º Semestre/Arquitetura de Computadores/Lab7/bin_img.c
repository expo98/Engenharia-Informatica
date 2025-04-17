void bin_img(unsigned char *ptr, int w, int h, unsigned char limiar)
{
  int i=0;
  for (; i < w; i++)
  {
    int j =0;
    for (; j < h; j++)
    {
      if (*ptr<=limiar)
      {
        *ptr = 0;
      }
      else *ptr = 255;
      ptr++;
    }
  }
  
  
}