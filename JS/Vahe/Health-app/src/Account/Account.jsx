import React from 'react';
import './Account.css';
import { H4, H5, Avatar, Switch } from 'ui-neumorphism';

class Account extends React.Component {
    render () {
        const {dark, setMode} = this.props;
        return (
            <div>
                <H4 className='account-title' dark = {dark}>Acconut</H4>
                <div className = 'person' flat>
                    <Avatar
                        bgColor = 'brown'
                        size = '150'
                        className = 'profile-photo'
                        src='https://www.searchpng.com/wp-content/uploads/2019/02/Profile-PNG-Icon-715x715.png'
                    />
                    <H5 dark = {dark}>Anounymous</H5>
                </div>
                <Switch label = 'Dark mode' dark = {dark} className = 'mode-switcher' onChange = {(event) => {
                    if (dark === false) {
                        setMode(true);
                    } else {
                        setMode(false);
                    }
                }}/>
            </div>
        )
    }
}

export default Account;
