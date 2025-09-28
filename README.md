# baitap1 an toàn và bảo mật thông tin
# Lê Ngọc Tú msv k225480106069
# 1. Caesar
 mã hóa   P → C = (P + k) mod 26
 giải mã  P = (C − k + 26) mod 26
 Không gian khoá : Tổng 25 khả năng thực tế.
 Cách phá mã (không cần khoá)
Brute force: thử 25 khóa, đọc kết quả
c++
<img width="976" height="427" alt="image" src="https://github.com/user-attachments/assets/37e39811-b924-463a-ac83-a7236a5b2611" />
html+css+js
<img width="1046" height="491" alt="image" src="https://github.com/user-attachments/assets/724d591b-3314-4897-b363-cc6777539a4b" />
# 2 Affine — biến thể tuyến tính của Caesar
mã hóa
P → C = (a*P + b) mod 26, a và b là khóa
giải mã
P = a⁻¹ * (C - b) mod 26
Không gian khóa
a có 12 giá trị khả dĩ (cùng nguyên tố với 26), b có 26 giá trị → 312 khóa
Số a: các số trong 1..25 coprime với 26 → 12 giá trị. b có 26 giá trị.
12×26=312.
Cách phá mã (không cần khóa)
Phân tích tần suất, thử tất cả khóa a,b
c++
<img width="962" height="424" alt="image" src="https://github.com/user-attachments/assets/8cc79538-c753-4556-baa6-3f288cdea6ca" />
html+css+js
<img width="1015" height="478" alt="image" src="https://github.com/user-attachments/assets/51a3c38f-898c-403a-8be9-5d1fb944e150" />
# 3 hoán vị - Permutation
mã hóa
Sắp xếp lại vị trí ký tự theo một khóa k
giải mã
dùng hoán vị nghịch đảo p^-1
Không gian khóa
 n!
Cách phá mã (không cần khóa)
Phân tích cấu trúc, tìm các mẫu lặp, đoán cấu trúc cột hoặc hàng
c++
<img width="974" height="457" alt="image" src="https://github.com/user-attachments/assets/ee5ebace-b8e5-4537-a1f7-95cf2c3ff8c4" />
html+css+js
<img width="1185" height="495" alt="image" src="https://github.com/user-attachments/assets/e3470203-76e0-42af-90d2-d97da4337926" />
