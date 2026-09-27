#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char maPhieu[MAX][15];
    char tenSach[MAX][50];
    int soNgayMuon[MAX];
    int tienPhat[MAX];
    int soLuong = 0;
    int choice;

    do {
        printf("================ HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS) ================\n");
        printf("1. Them luot muon sach moi\n");
        printf("2. Hien thi danh sach muon sach\n");
        printf("3. Cap nhat so ngay muon theo Ma phieu\n");
        printf("4. Xoa luot muon sach theo Ma phieu\n");
        printf("5. Thong ke danh sach phieu muon bi phat (Qua han > 14 ngay)\n");
        printf("6. Thoat chuong trinh\n");
        printf("==============================================================================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (soLuong >= MAX) {
                    printf("He thong day, khong the them phieu muon moi!\n");
                    break;
                }
                char tempMa[15];
                printf("Nhap ma phieu muon: ");
                scanf("%s", tempMa);

                int trung = 0;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], tempMa) == 0) {
                        trung = 1;
                        break;
                    }
                }
                if (trung) {
                    printf("Ma phieu da ton tai! Huy thao tac them.\n");
                    printf("\n");
                    break;
                }
                strcpy(maPhieu[soLuong], tempMa);

                while (getchar() != '\n');

                printf("Nhap ten sach: ");
                fgets(tenSach[soLuong], sizeof(tenSach[soLuong]), stdin);
                size_t len = strlen(tenSach[soLuong]);
                if (len > 0 && tenSach[soLuong][len - 1] == '\n') {
                    tenSach[soLuong][len - 1] = '\0';
                }

                int ngay;
                do {
                    printf("Nhap so ngay muon thuc te: ");
                    scanf("%d", &ngay);
                    if (ngay <= 0) {
                        printf("So ngay muon phai lon hon 0. Vui long nhap lai!\n");
                    }
                } while (ngay <= 0);

                soNgayMuon[soLuong] = ngay;
                if (ngay > 14) {
                    tienPhat[soLuong] = (ngay - 14) * 5000;
                } else {
                    tienPhat[soLuong] = 0;
                }
                soLuong++;
                printf("Them luot muon sach thanh cong!\n");
                printf("\n");
                break;
            }
            case 2: {
                if (soLuong == 0) {
                    printf("Danh sach muon sach hien dang rong!\n");
                } else {
                    printf("\n================================ DANH SACH MUON SACH ================================\n");
                    printf("STT | Ma Phieu     | Ten Sach                                             | So Ngay     | Tien Phat (VND)\n");
                    printf("-------------------------------------------------------------------------------------\n");
                    int tongTien = 0;
                    for (int i = 0; i < soLuong; i++) {
                        printf("%-3d | %-12s | %-44s | %-11d | %-15d\n", i + 1, maPhieu[i], tenSach[i], soNgayMuon[i], tienPhat[i]);
                        tongTien += tienPhat[i];
                    }
                    printf("-------------------------------------------------------------------------------------\n");
                    printf("Tong tien phat toan he thong: %d VND\n", tongTien);
                }
                printf("\n");
                break;
            }
            case 3: {
                char tempMa[15];
                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%s", tempMa);
                int found = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], tempMa) == 0) {
                        found = i;
                        break;
                    }
                }
                if (found == -1) {
                    printf("Khong tim thay phieu muon co ma: %s\n", tempMa);
                } else {
                    printf("Tim thay phieu muon cua sach: %s (So ngay hien tai: %d)\n", tenSach[found], soNgayMuon[found]);
                    int ngayMoi;
                    do {
                        printf("Nhap so ngay muon thuc te moi: ");
                        scanf("%d", &ngayMoi);
                        if (ngayMoi <= 0) {
                            printf("So ngay muon phai lon hon 0. Vui long nhap lai!\n");
                        }
                    } while (ngayMoi <= 0);

                    soNgayMuon[found] = ngayMoi;
                    if (ngayMoi > 14) {
                        tienPhat[found] = (ngayMoi - 14) * 5000;
                    } else {
                        tienPhat[found] = 0;
                    }
                    printf("Cap nhat so ngay muon thanh cong!\n");
                }
                printf("\n");
                break;
            }
            case 4: {
                char tempMa[15];
                printf("Nhap ma phieu muon can xoa: ");
                scanf("%s", tempMa);
                int found = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], tempMa) == 0) {
                        found = i;
                        break;
                    }
                }
                if (found == -1) {
                    printf("Khong tim thay phieu muon co ma: %s\n", tempMa);
                } else {
                    for (int i = found; i < soLuong - 1; i++) {
                        strcpy(maPhieu[i], maPhieu[i + 1]);
                        strcpy(tenSach[i], tenSach[i + 1]);
                        soNgayMuon[i] = soNgayMuon[i + 1];
                        tienPhat[i] = tienPhat[i + 1];
                    }
                    soLuong--;
                    printf("Xoa phieu muon thanh cong!\n");
                }
                printf("\n");
                break;
            }
            case 5: {
                int count = 0;
                for (int i = 0; i < soLuong; i++) {
                    if (soNgayMuon[i] > 14) {
                        if (count == 0) {
                            printf("========================= DANH SACH PHIEU MUON QUA HAN =========================\n");
                            printf("STT | Ma Phieu     | Ten Sach                                             | So Ngay     | Tien Phat (VND)\n");
                            printf("-------------------------------------------------------------------------------------\n");
                        }
                        count++;
                        printf("%-3d | %-12s | %-44s | %-11d | %-15d\n", count, maPhieu[i], tenSach[i], soNgayMuon[i], tienPhat[i]);
                    }
                }
                if (count == 0) {
                    printf("Khong co luot muon nao bi qua han phat!\n");
                } else {
                    printf("-------------------------------------------------------------------------------------\n");
                }
                printf("\n");
                break;
            }
            case 6: {
                printf("Thoat chuong trinh. Tam biet!\n");
                break;
            }
            default: {
                printf("Lua chon khong hop le. Vui long nhap lai!\n");
                printf("\n");
                break;
            }
        }
    } while (choice != 6);

    return 0;
}
