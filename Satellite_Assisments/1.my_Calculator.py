class Calc:
    def add(self, num_1, num_2):
        result = num_1 + num_2
        print(f"The addition of num1 = {num_1} and num2 = {num_2} is {result}")
        return result

    def sub(self, num_1, num_2):
        result = num_1 - num_2
        print(f"The subtraction of num1 = {num_1} and num2 = {num_2} is {result}")
        return result

    def mul(self, num_1, num_2):
        result = num_1 * num_2
        print(f"The multiplication of num1 = {num_1} and num2 = {num_2} is {result}")
        return result

    def div(self, num_1, num_2):
        if num_2 != 0:
            result = num_1 / num_2
            print(f"The division of num1 = {num_1} and num2 = {num_2} is {result}")
            return result
        else:
            print("Can't divide by zero — kindly give a different number")
            return None
