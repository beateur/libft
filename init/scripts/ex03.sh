echo "Listing upgradable packages:"
apt list --upgradable
read -p "Upgrade packages? (Y/N)" yn
case $yn in
	[Yy]* ) sudo apt update && sudo apt upgrade; exit;;
	[Nn]* ) exit;;
		* ) echo "Please answer yes or no.";;
esac
