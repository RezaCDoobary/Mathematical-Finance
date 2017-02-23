import pandas as pd
import matplotlib.pyplot as plt

#Here we use the csv files to construct plots and perform data analysis.

w = []
w.append([pd.read_csv('price_analytic_vol_exp=0.5.csv'),0.5])
w.append([pd.read_csv('price_analytic_vol_exp=1.csv'),1])
w.append([pd.read_csv('price_analytic_vol_exp=1.5.csv'),1.5])
w.append([pd.read_csv('price_analytic_vol_exp=2.csv'),2])
w.append([pd.read_csv('price_analytic_vol_exp=3.csv'),3])
w.append([pd.read_csv('price_analytic_vol_exp=4.csv'),4])
w.append([pd.read_csv('price_analytic_vol_exp=5.csv'),5])

fig = plt.figure(figsize=(8,8))
for i in range(0, len(w)):
    x = w[i][0]['vol'].as_matrix()
    y = w[i][0]['price'].as_matrix()
    plt.plot(x,y,label="expiration = " + str(w[i][1]))
ax = fig.add_subplot(111)
plt.legend(loc='lower right')
ax.set_title('analytically computed euro call option via Black-Scholes model price vs. Volatility')
ax.set_xlabel('volatility')
ax.set_ylabel('price')
plt.savefig('eurocall_analytic.pdf')
plt.show()

q = []
q.append([pd.read_csv('price_monte_carlo_vol_exp=0.5.csv'),0.5])
q.append([pd.read_csv('price_monte_carlo_vol_exp=1.csv'),1])
q.append([pd.read_csv('price_monte_carlo_vol_exp=1.5.csv'),1.5])
q.append([pd.read_csv('price_monte_carlo_vol_exp=2.csv'),2])
q.append([pd.read_csv('price_monte_carlo_vol_exp=3.csv'),3])
q.append([pd.read_csv('price_monte_carlo_vol_exp=4.csv'),4])
q.append([pd.read_csv('price_monte_carlo_vol_exp=5.csv'),5])

fig1 = plt.figure(figsize=(8,8))
for i in range(0, len(q)):
    x = q[i][0]['vol'].as_matrix()
    y = q[i][0]['price'].as_matrix()
    plt.plot(x,y,label="expiration = " + str(q[i][1]))
ax = fig1.add_subplot(111)
plt.legend(loc='upper left')
ax.set_title('numerically (monte-carlo) computed euro call option via Black-Scholes model price vs. Volatility')
ax.set_xlabel('volatility')
ax.set_ylabel('price')
plt.savefig('eurocall_numeric.pdf')
plt.show()


t = []
t.append([pd.read_csv('digi_price_analytic_vol_exp=0.5.csv'),0.5])
t.append([pd.read_csv('digi_price_analytic_vol_exp=1.csv'),1])
t.append([pd.read_csv('digi_price_analytic_vol_exp=1.5.csv'),1.5])
t.append([pd.read_csv('digi_price_analytic_vol_exp=2.csv'),2])
t.append([pd.read_csv('digi_price_analytic_vol_exp=3.csv'),3])
t.append([pd.read_csv('digi_price_analytic_vol_exp=4.csv'),4])
t.append([pd.read_csv('digi_price_analytic_vol_exp=5.csv'),5])

fig2 = plt.figure(figsize=(8,8))
for i in range(0, len(t)):
    x = t[i][0]['vol'].as_matrix()
    y = t[i][0]['price'].as_matrix()
    plt.plot(x,y,label="expiration = " + str(t[i][1]))
ax = fig2.add_subplot(111)
plt.legend(loc='upper right')
ax.set_title('analytically computed digital call option Black-Scholes model price vs. Volatility')
ax.set_xlabel('volatility')
ax.set_ylabel('price')
plt.savefig('digicall_analytic.pdf')
plt.show()

