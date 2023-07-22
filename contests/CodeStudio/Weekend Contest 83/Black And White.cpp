int minOperations(int x, int a, int b)
{

    if ((b - a) > 0 && x % (b - a) == 0)
    {

        int i = x / (b - a);
        return i;
    }
    else
    {

        return -1;
    }
}
