#include<stdio.h>

int nine(){

    int ans=0;
    int m,p,n;
    scanf("%d",&m);
    scanf("%d",&p);
    int arr1[m][p];
    int i,j,k;
    for(i=0;i<m;i++){
        for(j=0;j<p;j++){
            scanf("%d",&arr1[i][j]);
        }
    }
    scanf("%d",&p);
    scanf("%d",&n);
    int arr2[p][n];
    for(i=0;i<p;i++){
        for(j=0;j<n;j++){
            scanf("%d",&arr2[i][j]);
        }
    }

    for(i=0;i<m;i++){
        for(j=0;j<p;j++){
            for(k=0;k<n;k++){
                ans+=(arr1[i][j]*arr2[j][k]);
            }
        }
    }
    printf("%d",ans);
    return 0;
}
