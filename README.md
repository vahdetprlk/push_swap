# push_swap

Bu proje, verilen verileri bir yığın üzerinde sınırlı bir dizi talimat kullanarak sıralamayı amaçlar. Aşağıdaki talimatları kullanarak verileri manipüle etmek ve mümkün olan en az sayıda işlemle sıralamayı gerçekleştirmek hedeflenir.

## Giriş

42 Okullarının müfredatında bulunan Push_swap projesi, verileri sıralama üzerinde odaklanan bir algoritma projesidir. Projede, bir dizi tamsayı değeri, iki yığın ve yığınları manipüle etmek için talimatlar sağlanır. Amacımız, verilen tamsayıları sıralamak için en küçük programı hesaplayan ve gösteren bir `push_swap` adında bir C programı yazmaktır.

## Hedefler

Bu projenin hedefleri arasında bir sıralama algoritması geliştirmek, karmaşıklık analizi konusunda deneyim kazanmak ve C programlama dili kullanarak temel algoritmaları pratik yapmak bulunur.

## Kullanım

Projenin nasıl çalıştırılacağına dair talimatları aşağıda bulabilirsiniz:

1. İlk adımda, projeyi yerel bir dizine klonlayın.

3. Proje dizinine gidin.

3. Ardından, `make all` komutunu kullanarak projeyi derleyin.


4. Derleme işlemi tamamlandıktan sonra, `push_swap` programını çalıştırın ve tamsayı listesini argüman olarak verin:

./push_swap 4 2 7 1 5

Bu komut, verilen tamsayı listesini sıralamak için kullanılacak en küçük talimat listesini ekrana yazdıracaktır.

5. Ayrıca, `checker` programını da kullanarak sıralamanın doğruluğunu kontrol edebilirsiniz. `checker` programı, `push_swap` programının ürettiği talimat listesini alacak ve bu talimatları kullanarak tamsayı listesini kontrol edecektir:

./push_swap 4 2 7 1 5 | ./checker 4 2 7 1 5


Eğer tamsayı listesi doğru bir şekilde sıralandıysa, `OK` mesajı görüntülenecektir. Aksi takdirde, `KO` mesajı alacaksınız.

## Algoritma:
Bu push_swap projesinde "Quick Sort" algoritması kullanıldı. Projede, verilen verileri sıralamak için en uygun algoritmayı belirlemek ve en az sayıda adımda sıralamayı gerçekleştirmek amaçlanır.

- Quick Sort: Bu algoritma, verileri bir pivot elemanı etrafında bölerek sıralama yapar. İlk olarak, bir pivot elemanı seçilir. Daha sonra, pivot elemanından daha küçük olanlar bir yığında toplanırken, pivot elemanından daha büyük olanlar diğer yığında toplanır. Bu işlem, iki yığında da ayrışma işlemi tamamlanana kadar tekrarlanır. Ardından, ayrıştırılmış yığınlar aynı işlemle sıralanır ve birleştirilir.

## Veri Yapısı:
Push_swap projesinde, verileri saklamak ve manipüle etmek için iki yığın kullanılır. Bu yığınlar, verileri bellekte tutan ve sıralama işlemlerini gerçekleştiren veri yapılarıdır.

1. Birincil Yığın (Stack A): Bu yığın, sıralanacak tamsayı verilerini tutar. İşlemler bu yığın üzerinde gerçekleştirilir. Yığın üzerindeki işlemler şunları içerebilir: veri ekleme, veri çıkarma, yığını boşaltma.

2. İkincil Yığın (Stack B): Bu yığın, geçici olarak verileri saklamak için kullanılır. Özellikle, Insertion Sort algoritmasında kullanılır. Veriler, birincil yığından ikincil yığına aktarılır, sıralama işlemi gerçekleştirildikten sonra tekrar birincil yığına aktarılır.

Bu yığın yapıları iki yönlü bağlı liste (Doubly Linked List) kullanılarak oluşturulumuştur. Her düğüm, hem bir önceki düğüme hem de bir sonraki düğüme referansları olan bir yapıya sahiptir. Bu özellik, liste üzerinde hem ileri hem de geri yönlü gezinmeyi sağlar ve ilk giren son çıkar (FILO) şeklinde çalışmaktadır.  

Yukarıdaki veri yapıları, verileri düzenlemek ve sıralama algoritmalarını uygulamak için projede kullanılan temel yapıları temsil eder.
