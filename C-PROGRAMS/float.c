struct mas {
    float m;
};

int main(void)
{
    struct mas *ms;
    ms=(struct mas*)malloc(sizeof(struct mas));
    scanf("%f",&(ms->m));
    printf("%f",ms->m);
    return 0;
}

