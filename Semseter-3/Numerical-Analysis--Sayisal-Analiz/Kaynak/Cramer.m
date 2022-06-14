function kokler = Cramer(matrix,E)
MI1=[E' matrix(:,[2 3 4])];
MI2=[matrix(:,1) E' matrix(:,[3 4])];
MI3=[matrix(:,[1 2]) E' matrix(:,4)];
MI4=[matrix(:,[1 2 3]) E'];
kokler = [det(MI1);det(MI2);det(MI3);det(MI4)]/det(matrix);
end

