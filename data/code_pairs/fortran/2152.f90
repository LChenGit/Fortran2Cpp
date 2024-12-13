! example.f90
program example

    implicit none
    double precision :: evaluate
    integer :: myMutation
    double precision :: pm
    integer :: n, mutationResult
    double precision :: evalResult

    pm = 0.5  ! Example mutation probability.
    n = 10    ! Example population size for evaluation.

    evalResult = evaluate(n)
    print *, 'Evaluate function result: ', evalResult
    if (evalResult == 55.0) then
        print *, 'Evaluate function test passed.'
    else
        print *, 'Evaluate function test failed.'
    end if

    mutationResult = myMutation(pm)
    print *, 'Mutation function result (0 or 1): ', mutationResult
    if (mutationResult == 0 .or. mutationResult == 1) then
        print *, 'Mutation function test passed.'
    else
        print *, 'Mutation function test failed.'
    end if

contains

    double precision function evaluate(n)
        implicit none
        integer, intent(in) :: n
        integer :: i
        evaluate = 0
        do i = 1, n
            evaluate = evaluate + i
        end do
    end function evaluate

    integer function myMutation(pm)
        implicit none
        double precision, intent(in) :: pm
        double precision :: r
        call random_seed()
        call random_number(r)
        if (r < pm) then
            myMutation = 1
        else
            myMutation = 0
        end if
    end function myMutation

end program example