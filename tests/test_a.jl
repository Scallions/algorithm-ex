using Test
@testset "Foo tests" begin
    @testset "A" begin
        @test 1 == 1
        @test 2 == 3
    end
end

@testset "Foo tests2" begin
    @testset "B" begin
        @test 3 == 3
        @test 4 == 4
    end
end