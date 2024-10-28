char *
ft_memcpy (destaddr, srcaddr, len)
{
  char *dest = destaddr;

  while (len > 0)
  {
    *destaddr = *srcaddr;
    destaddr++;
    srcaddr++;
    len--;
  }
  return dest;
}