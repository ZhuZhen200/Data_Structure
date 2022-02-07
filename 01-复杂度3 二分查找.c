Position BinarySearch( List L, ElementType X )
{
    Position Left, Right, Mid;
    
    Left = 1;
    Right = L->Last;
    while (Left <= Right)
    {
        Mid = (Left + Right) / 2;
        if (X == L->Data[Mid])
            return Mid;
        else if (X > L->Data[Mid])
            Left = Mid + 1;
        else if (X < L->Data[Mid])
            Right = Mid -1;
    }
    return NotFound;
}
