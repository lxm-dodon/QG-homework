import numpy as np


def spl(test_ratio, X, Y):            # test_radio表示测试集占比e.g.test_radio = 0.2
    # X表示特征值，Y表示目标值
    remix = np.random.permutation(len(X))   # 洗乱一维数组之间的顺序
    test_size = int(len(X)*test_ratio)
    test_index = remix[:test_size]      # 测试集
    train_index = remix[test_size:]     # 训练集
    X_train = X[train_index]            # 训练集的特征值
    Y_train = Y[train_index]            # 训练集的目标值
    X_test = X[test_index]
    Y_test = Y[test_index]
    return X_train, X_test, Y_train, Y_test
