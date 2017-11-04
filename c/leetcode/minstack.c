
typedef struct {
	int min_idx;
	int idx;
	int buffer[];
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(const int maxSize)
{
	MinStack* const s = malloc(sizeof(MinStack) + sizeof(int) * maxSize);
	s->idx = 0;
	s->min_idx = 0;
	return s;
}

void minStackPush(MinStack* const obj, const int x)
{
	if (obj->idx != 0 && x < obj->buffer[obj->min_idx])
		obj->min_idx = obj->idx;
	obj->buffer[obj->idx++] = x;
}

void minStackPop(MinStack* const obj)
{
	--obj->idx;
	if (obj->idx == obj->min_idx) {
		int min = obj->buffer[0];
		int idx = 0;
		for (int i = 1; i < obj->idx; ++i) {
			if (obj->buffer[i] < min) {
				min = obj->buffer[i];
				idx = i;
			}
		}
		obj->min_idx = idx;
	}
}

int minStackTop(MinStack* const obj)
{
	return obj->buffer[obj->idx - 1];
}

int minStackGetMin(MinStack* const obj)
{
	return obj->buffer[obj->min_idx];
}

void minStackFree(MinStack* const obj)
{
	free(obj);    
}


