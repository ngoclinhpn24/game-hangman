# game-hangman
1. Giới thiệu chung
- Đây là trò chơi giữa người và máy theo kiểu đoán từ dựa vào số ký tự của từ đó
- Máy sẽ chọn ra 1 từ trong list từ vựng và đưa ra số ký tự của từ đó dưới dạng một hàng gạch ngang
- Người chơi sẽ lần lượt đoán các chữ cái mà họ cho là có mặt trong từ 
  - Mỗi lần đoán đúng thì các gạch ngang tương ứng sẽ được thay bằng chữ cái đoán được
  - Mỗi lần đoán sai thì "giá treo cổ" sẽ được vẽ thêm một nét của "người treo cổ"
- Cuộc chơi kết thúc khi một từ được đoán đúng hoặc hình người treo cổ (thường gồm 6 nét, tương ứng 6 lần đoán sai) bị hoàn tất

2. Giao diện
- Giao diện mở đầu

![image](https://user-images.githubusercontent.com/59814921/120260706-9e489b80-c2c0-11eb-9b9c-3aa6fa7b5bf2.png)

- Bắt đầu trò chơi

![image](https://user-images.githubusercontent.com/59814921/120260218-a5bb7500-c2bf-11eb-96bc-9fd7cdf1125f.png)
![image](https://user-images.githubusercontent.com/59814921/120260741-ad2f4e00-c2c0-11eb-870d-4f6315c80054.png)
