
typedef struct {
	int min_idx;
	int idx;
	int buffer[];
} MinStack;

/** initialize your data structure here. */
static MinStack* minStackCreate(const int maxSize)
{
	MinStack* const s = malloc(sizeof(MinStack) + sizeof(int) * maxSize);
	s->idx = 0;
	s->min_idx = 0;
	return s;
}

static void minStackPush(MinStack* const s, const int x)
{
	if (s->idx != 0 && x < s->buffer[s->min_idx])
		s->min_idx = s->idx;
	s->buffer[s->idx++] = x;
}

static void minStackPop(MinStack* const s)
{
	--s->idx;
	if (s->idx == s->min_idx) {
		int min = s->buffer[0];
		int idx = 0;
		for (int i = 1; i < s->idx; ++i) {
			if (s->buffer[i] < min) {
				min = s->buffer[i];
				idx = i;
			}
		}
		s->min_idx = idx;
	}
}

static int minStackTop(const MinStack* const s)
{
	return s->buffer[s->idx - 1];
}

static int minStackGetMin(const MinStack* const s)
{
	return s->buffer[s->min_idx];
}

static void minStackFree(MinStack* const s)
{
	free(s);    
}


