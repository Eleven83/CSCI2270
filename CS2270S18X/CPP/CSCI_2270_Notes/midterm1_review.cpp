/** problem 1**/
int ShiftArray(Product arr[],int size,int target)
{
    for(int j = size-1;j>=0;j--)
    {
        if(arr[j].price ==  target)
        {
            if(j!= size-1)
            {
                for(int i=j+1;i<size;i++)
                    arr[i-1] = arr[i];
            }
            size = size-1;
        }
    }
    return size;
}

/** problem2**/
struct Count{
    string pname;
    int count;
};

string commonRepeatingElement(Product arr[],int length)
{
    Count* cArr = new Count[length];
    int uniqueItm = 0;
    int max =-1;
    string maxItem;
    /** iterate over the array**/
    for(int i=0; i<length;i++)
    {
        int j=0;
            /*check whether it has already in the array.
                update only the count*/
            for( j=0;j<uniqueItm;j++)
            {
                if(cArr[j].pname == arr[i].pname)
                {
                    cArr[j].count+= 1;
                    if(max<cArr[j].count)
                    {
                        max = cArr[j].count;
                        maxItem = arr[i].pname;
                    }

                }
            }
            /**
                for the first time we are discovering it
            */
            if(j == uniqueItm)
            {
                cArr[j].pname = arr[i].pname;
                cArr[j].count = 1;
                uniqueItm++;
                if(max<cArr[j].count)
                    {
                        max = cArr[j].count;
                        maxItem = arr[i].pname;
                    }
            }

    }
    return maxItem;
}
/** problem 3**/
int *CopyArray(int array[], int length, int value)
{
    int repeat = 0;
    /** look for the value **/
    for(int i=0;i<length;i++)
    {
        if(array[i] == value)
            repeat++;
    }
    /** if no occurance**/
    if(repeat<1)
        return &array[0];
    else{/** otherwise**/
        int newSize = length - repeat;// new array size
        int* newArr = new int [newSize];// new array
        int count = 0;
        // copy from old array to new array
        for(int i=0;i<length;i++)
        {
            if(array[i]!=value)
            {
                newArr[count++] =  array[i];
            }
        }
      return newArr;
    }
    return NULL;
}

/** problem 4 **/
int secondLargest(int a[],int size)
{
    int max = -999;// largest
    int max2 = -999;//second largest

    for(int i=0;i<size;i++)// iterate over the array
    {
        if(a[i]>max){// current element is larger than max
            max2 = max;
            max = a[i];
        }
        else if(a[i]> max2 && a[i]<=max ) //current element is smaller than max but larger than second largeest
        {
            max2 = a[i];
        }
    }
    return max2;
}
/** 5**/
void findMax()
{
    Node* temp = head;
    int max = -999;
    while(temp)
    {
        if(temp->key > max)
            max=temp->key;
        temp=temp->next;
    }
    if(max!=-999)
        cout<<max;
}
/**6**/
void Queue::enqueue(node* newNode)
{
    if(tail==NULL)//empty
    {
        head=newNode;
        tail=head;
    }
    else{
        tail->next=newNode;
        tail=newNode;
        tail->next=NULL;
    }
}
/*** deque***/
node* Queue::dequeue()
{
    if(head==NULL)// no element in the queue
    {
        tail=NULL;
        return NULL;
    }
    else if(head==tail)// only element in the queue
    {
        node* temp=head;
        head=NULL;
        tail=NULL;
        return temp;
    }
    else{
        node* temp=head;
        head=head->next;
        return temp;
    }
    return NULL;
}
