import socket,time

ServerIP = '192.168.8.8'
ServerPort = 80
Timeout = 0.001 #2second


def SycConnect(skt):
    while 1:
        try:
            skt.connect((ServerIP,ServerPort))
            print("连接成功！")
            break
        except socket.timeout:
            print("连接失败，重试。。。")
            continue
        except OSError:
            print("Arp 协议等待，重试中")
            time.sleep(1)
            continue
phone = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
phone.settimeout(Timeout)
SycConnect(phone)
# 连接
while 1:
    # 连接检查
    status = phone.getsockopt(socket.SOL_SOCKET, socket.SO_ERROR)
    if status != 0:
        SycConnect(phone)

    # 用户输入
    client_data = input('>>>')
    client_data = client_data + '\n'

    # 尝试发送
    try:
        phone.send(client_data.encode('utf-8'))
    except ConnectionResetError:
        print("主机reset，重新连接")
        phone.close()
        phone = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        phone.settimeout(Timeout)
        SycConnect(phone)
        continue
    except socket.timeout:
        print("发送超时")
        phone.close()
        phone = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        phone.settimeout(Timeout)
        SycConnect(phone)
        continue
    # 接收数据
    AllRecvData = b''
    while 1:
        try:
            from_server_data = phone.recv(1024)
        except socket.timeout:
            break
        if not from_server_data:
            break
        AllRecvData += from_server_data
    print(from_server_data.decode('utf-8'))


phone.close()
