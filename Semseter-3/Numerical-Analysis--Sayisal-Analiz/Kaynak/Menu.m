disp('4 Adet doğrusal denklem giriniz');

for i=1:4
    fprintf('%d. denklem için katsayıları giriniz: \n',i);
    for j=1:4
        fprintf('Matrix(%d,%d)=',i,j);
        Matrix(i,j)=input(' ');
        if j==4
            E(i)=input('Empedans değeri: ');
        end
    end
end

%Matrix=[6 3 2 1;3 5 2 1;1 1 2 5;2 2 4 2];
%E=[12 11 9 5];
% kökler   1.3125    1.4688   -0.9531    1.6250

disp('1-) Cramer yöntemi');
disp('2-) Matrisin tersini alarak bulma yöntemi');
disp('3-) Gauss eleme yöntemi');
n = input('İşlem seçimi: ');
switch n
    case 1
        Cramer(Matrix,E)
    case 2
        MatrisTersi(Matrix,E)
    case 3
        Gauss(Matrix,E)
    otherwise
        disp('Geçersiz seçim')
end

