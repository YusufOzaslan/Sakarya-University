function kokler = Gauss(matrix,E)
denklemTakimi=[matrix E'];
M=size(denklemTakimi,1);N=size(denklemTakimi,2);
% Yok etme yöntemi kullanılır
for i=1:M-1
    for j=i+1:M
        katsayi=denklemTakimi(j,i)/denklemTakimi(i,i);
        for k=1:N
            denklemTakimi(j,k)=denklemTakimi(j,k)-katsayi*denklemTakimi(i,k);
        end
    end
end
% Değerler yerine koyulur
kokler(M)=denklemTakimi(M,N)/denklemTakimi(M,M);
for i=M-1:-1:1
    Toplam=0;
    for j=i+1:M
        Toplam=Toplam+denklemTakimi(i,j)*kokler(j);
    end
    kokler(i)=1/denklemTakimi(i,i)*(denklemTakimi(i,N)-Toplam);
end
end

