int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i,j;
    int* r = (int*)malloc(sizeof(int)*2);
    *returnSize = 2;
     
    for (i = 0; i < numsSize;i++)
    {
        for (j= i + 1; j < numsSize;j++)
        {
            if ((nums[i]+nums[j]) == target)
            {
                r[0] = i;
                r[1] = j;
            }
        }
    }    
    return r;
}
