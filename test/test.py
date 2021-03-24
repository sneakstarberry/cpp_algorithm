import copy

FLAG = False


def type_verifier(item):

    if str(type(item)) == "<class 'int'>":
        return "NUMBER"
    elif str(type(item)) == "<class 'str'>":
        return "STRING"
    else:
        return "NULL"


def flag_rule_validator(flag_rule, command, i):
    global FLAG
    flag_rule = flag_rule.split(' ')
    if flag_rule[0] == command[i]:
        FLAG = True
        if flag_rule[1] == "NUMBER":
            if command[i+1].isnumeric() == False:
                return 1
            command[i+1] = int(command[i+1])
        if flag_rule[1] != type_verifier(command[i+1]):
            return 1


def command_validator(program, flag_rules, command):
    global FLAG
    command = command.split(' ')
    if command[0] != program:
        return "False"
    for i in range(1, len(command)-1):
        for flag_rule in flag_rules:
            copy_flag_rule = copy.deepcopy(flag_rule)

            if flag_rule_validator(copy_flag_rule, command, i):
                return "False"
    return "True"


def solution(program, flag_rules, commands):
    answer = []
    for command in commands:
        copy_command = copy.deepcopy(command)
        print(command_validator(program, flag_rules, copy_command))
    return answer


solution("line", ["-s STRING", "-n NUMBER", "-e NULL"],
         ["line -s 123 -n HI", "line fun"])
