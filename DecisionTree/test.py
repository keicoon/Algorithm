import './index.py' as decision_tree

trains = load('./data/train_dt')
tests = load('./data/test_dt')

tree = decision_tree(trains)

for test in tests:
    test_data, label = test
    print(tree.classify(test_data), label)