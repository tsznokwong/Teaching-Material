Program Algorithm;
var
    arr: array [1..8] of integer = (5, 6, 10, 7, 3, 2, 9, 1);
const
    size = 8;


procedure Swap(var x, y: integer);
var temp: integer;
begin
    temp := x;
    x := y;
    y := temp;
end;

procedure BubbleSort;
var
    i, j: integer;
begin
    for i := 1 to size do
        for j := 1 to size - i do
            if arr[j] > arr[j+1] then
                Swap(arr[j], arr[j+1]);

end;

procedure InsertionSort;
var
    i, j: integer;
begin
    for i := 1 to size do 
        for j := i downto 2 do
            if arr[j] < arr[j-1] then
                Swap(arr[j], arr[j-1]);
end;

procedure Merge(low, high: integer);
var
    i, j, k: integer;
    temp: array[1..size] of integer;
    mid: integer;
begin
    mid := low + (high-low) div 2 + 1;
    i := low;
    j := mid;
    for k := low to high do
        if (i < mid) and ((j > high) or (arr[i] <= arr[j])) then
            begin
                temp[k] := arr[i];
                i := i + 1;
            end
        else
            begin
            temp[k] := arr[j];
            j := j + 1;
            end;
    for k := low to high do
        arr[k] := temp[k];
end;

procedure MergeSort(low, high: integer);
begin
    if high - low >= 1 then
    begin
        MergeSort(low, low + (high-low) div 2);
        MergeSort(low + (high-low) div 2 + 1, high);
        Merge(low, high);
    end;
end;

procedure printArray;
var
    i: integer;
begin
    for i := 1 to size do
        write(arr[i], ' ');
    writeln;
end;

function linearSearch(target: integer): integer;
var
    i: integer;
begin
    linearSearch := 0;
    for i := 1 to size do
        if arr[i] = target then
            linearSearch := i;
end;

function binarySearch(target: integer): integer;
var 
    low, mid, high: integer;
begin
    low := 0;
    high := size + 1;
    while high - low > 1 do
    begin
        mid := (high+low) div 2;
        if target <= arr[mid] then    
            high := mid
        else 
            low := mid;
    end;
    binarySearch := high;
end;

begin
    printArray();
    {BubbleSort();}
    {InsertionSort();}
    MergeSort(1, size);
    printArray();
    writeln(linearSearch(8));
    writeln(binarySearch(10));
end.
