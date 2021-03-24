Position BinarySearch(List L,ElementType X)
{
    int mid_position,end_position,begin_position;
    end_position = L.last;
    begin_position = 0;
    mid_position = L.Last/2;
    while(mid_position != X)
    {
        if (X == L.Data[mid_position]) break;
        else 
            if(X < L.Data[mid_position]) 
            {
                end_position = mid_position;
            }
            else 
            {
                begin_position = mid_position;
                
            }
        mid_position = (end_position + begin_position)/2;
    }
    return mid_position;
    //else if(X < L.Data[mid_position]) return BinarySearch(L,X)
}