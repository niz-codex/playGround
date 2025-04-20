#include <stdio.h>
#include <windows.h>

int main(){
    char error_msg[] = "Fuck You Dear Users!";
    for(int i = 0; i < 100; i++){
        MessageBox(NULL, error_msg, "This is Error Baby!", MB_OK);
    }
    return 0;
}

// New-Item -Path "C:\TestFolder\System32" -ItemType Directory
// Remove-Item -Path "C:\TestFolder\System32" -Recurse -Force
