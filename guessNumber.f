      program guessnumber     
      implicit none
      integer,parameter :: L=35
      integer :: n,a(9),g(9),XA(L),XB(L),s,gn(L),gi,check
      integer :: i,j,k,ANS,count
      real :: rand
      integer*4 :: time(9)
      character*3 :: tip
      print*,
     &'insert the dimensions(max=9) for the number u want to guess'
      read(*,*)n

 99   continue
      call itime(time)
      s=0
      do j=1,n
         s=s+time(j)
      enddo
      i=rand(s)
c G.N.
      do i=1,n
      a(i)=mod(rand(0)*1000.,10.)
      enddo
      
      do i=1,n-1
        do j=i+1,n
          if(a(i).eq.a(j))goto 99
        enddo
      enddo
c check for reapeated
          if(a(1).eq.0)goto 99
      do i=1,n
!         print*,a(i)
      enddo
c
      count=1
 100  continue
c 
      print*,'guess the number for 0~9, ex 1234, input 777 for ANS'
      if(count.gt.1)then
        do i=1,count-1
           write(*,"(i9,2x,i1,a1,1x,i1,a1)"),gn(i),XA(i),'A',XB(i),'B'
        enddo
      endif
      read(*,*)gn(count)
      if(gn(count).eq.777)goto 777 
      if(gn(count).lt.10**(n-1).or.gn(count).gt.10**n-1)then
      print*,'plz reinsert the number'
      goto 100
      endif
c setup for g(i)
      gi=gn(count)
      DO i=1,n
         g(i)=int(gi/10**(n-i))
         gi=gi-g(i)*10**(n-i)
      ENDDO
c check for repeated number 
 
      DO i=1,n-1
        do j=2,n
         if(i.ne.j.and.g(i).eq.g(j))then
          print*,'no repeated number'
          goto 100
         endif
        enddo
      ENDDO

       count=count+1
c check for ANS
      check=0
      XA(count-1)=0
      XB(count-1)=0
      DO i=1,n
         if(g(i).eq.a(i))check=check+1
           XA(count-1)=check
      ENDDO
       IF(check.eq.n)goto 777
c check for ?A?B
          do i=1,n
            do j=1,n
              if(i.ne.j.and.a(i).eq.g(j))XB(count-1)=XB(count-1)+1
            enddo
          enddo
       print*,XA(count-1),'A',XB(count-1),'B'
         goto 100
 777  continue
c
      ANS=0
      do i=1,n
         ANS=ANS+a(i)*10**(n-i)
      enddo
      write(*,"(a20,i9,3x,a7,1x,i3)"),
     &'Congratulations ANS=',ANS,'times=',count-1

      stop
      end
